#include <bits/stdc++.h>
using namespace std;

int find_distance(vector<int> &stalls, int N, int C, int st, int fn, int ans) {
    if (st > fn) return ans;

    int min_distance = st + (fn - st) / 2;
    int last_pos = stalls[0];
    bool possible = false;
    int cnt = 1;

    for (int i = 1; i < N; i++) {
        if (stalls[i] - last_pos >= min_distance) {
            cnt++;
            last_pos = stalls[i];
        }

        if (cnt >= C) {
            possible = true;
            break;
        }
    }
    if (possible) return find_distance(stalls, N, C, min_distance+1, fn, min_distance);
    else return find_distance(stalls, N, C, st, min_distance-1, ans);

}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N, C;
        cin >> N >> C;
        vector<int> stalls(N);

        for (int j = 0; j < N; j++) {
            cin >> stalls[j];
        }
        sort(stalls.begin(), stalls.end());
        int low = 0;
        int high = stalls[N-1] - stalls[0];

        cout << find_distance(stalls, N, C, low, high, 0) << endl;
    }
}