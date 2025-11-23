/*
 You will be given an array of N integers. Write a recursive function to calculate its summation.
*/

#include <bits/stdc++.h>
using namespace std;

int recursiveFunction(vector<int>& arr, int n) {
    if(n == 0) return 0;

    return recursiveFunction(arr, n - 1) + arr[n - 1];
}

int main() {
    int test_case = 1;
    int num_of_test;
    cin >> num_of_test;

    for(int T = 1; T <= num_of_test; T++) 
    {
        int total_integer;
        cin >> total_integer;

        vector<int> arr(total_integer);

        for(int i = 0; i < total_integer; i++){
            cin >> arr[i];
        }

        int res = recursiveFunction(arr, total_integer);
        cout << "Case " << test_case++ << ": " << res << endl;
    }

    return 0;
}