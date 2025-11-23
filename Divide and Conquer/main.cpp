#include<bits/stdc++.h>

using namespace std;

int exp(int b, int n) {
    if (n == 0)
        return 1;
    return exp(b, n-1)*b;
}

int fastExp(int b, int n) {
    if (n == 0)
        return 1;

    int prod = fastExp(b, n/2);

    if (n%2 == 0)
        return prod*prod;

    return prod*prod*b;
} 

int findSum(int arr[], int st, int fn) {
    if (st == fn)
        return arr[st];
    int mid = (st+fn)/2;
    int leftSum = findSum(arr, st, mid);
    int rightSum = findSum(arr, mid+1, fn);
    return leftSum + rightSum;
}

pair<int, int> findSecondMax(int arr[], int st, int fn) {
    if (st == fn)
        return make_pair(arr[st], INT_MIN);
    int mid = (st+fn)/2;
    pair<int, int> left = findSecondMax(arr, st, mid);
    pair<int, int> right = findSecondMax(arr, mid+1, fn);
    int maximum = max(left.first, right.first);
    int secondMax = max(min(left.first, right.first), max(left.second, right.second));
    return make_pair(maximum, secondMax);
}

int findPeak(int arr[], int st, int fn) {
    int mid = (st+fn)/2;
    if (arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1])
        return mid;
    if (arr[mid] > arr[mid-1])
        return findPeak(arr, mid+1, fn);
    return findPeak(arr, st, mid);
}

int main() {
    // cout << exp(3, 4) << endl;
    // int arr[] = {2, 3, 1, 5, 4, 6};
    // cout << findSum(arr, 0, 5) << endl;
    // cout << findSecondMax(arr, 0, 5).second << endl;
    int arr[] = {-1, 0, 2, 5, 6, 4, -2};
    cout << findPeak(arr, 0, 6) << endl;
}