/*
    You are given N sticks having distinct lengths;
    you have to form some triangles using the sticks.
    A triangle is valid if its area is positive.
    Your task is to find the number of ways you can
    form a valid triangle using the sticks.
*/

#include <bits/stdc++.h>
using namespace std;


int triangle_count(vector<int> &sticks, int st, int fn, int sum) {
    if (st > fn) return st;
    int mid = st + (fn - st) / 2;

    if (sum > sticks[mid]) return triangle_count(sticks, mid + 1, fn, sum);
    else return triangle_count(sticks, st, mid - 1, sum);
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        vector<int> sticks(N);

        for (int j = 0; j < N; j++) {
            cin >> sticks[j];
        }

        sort(sticks.begin(), sticks.end());
        int cnt = 0;

        for (int a = 0; a < N - 2; a++) {
            for (int b = a + 1; b < N - 1; b++) {
                int sum = sticks[a] + sticks[b];
                int limit_index = triangle_count(sticks, b+1, N-1, sum);
                int triangle_count = limit_index - (b + 1);
                cnt += triangle_count;
            }
        }

        cout << "Case " << i+1 << ": " << cnt << endl;
    }

    return 0;
}