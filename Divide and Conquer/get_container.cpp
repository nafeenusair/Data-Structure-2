#include <bits/stdc++.h>
using namespace std;

int solve_recursive(vector<int> &vessels, int N, int M, int st, int fn, int ans) {
    if (st > fn) return ans;

    int mid = st + (fn - st) / 2;

    int container_count = 1;
    int current_fill = 0;
    bool possible = true;

    for (int i = 0; i < N; i++) {
        if (vessels[i] > mid) {
            possible = false;
            break;
        }

        if (current_fill + vessels[i] <= mid) {
            current_fill += vessels[i];
        } else {
            container_count++;
            current_fill = vessels[i];
        }
    }

    if (container_count > M) possible = false;

    if (possible) {
        return solve_recursive(vessels, N, M, st, mid - 1, mid);
    }
    else {
        return solve_recursive(vessels, N, M, mid + 1, fn, ans);
    }
}

int main() {
    int T;
    if (cin >> T) {
        for (int i = 0; i < T; i++) {
            int n, m;
            cin >> n >> m;

            vector<int> vessels(n);
            int max_val = 0;
            int sum_val = 0;

            for (int j = 0; j < n; j++) {
                cin >> vessels[j];
                max_val = max(max_val, vessels[j]);
                sum_val += vessels[j];
            }

            int low = max_val;
            int high = sum_val;

            cout << "Case " << i + 1 << ": " << solve_recursive(vessels, n, m, low, high, high) << endl;
        }
    }
    return 0;
}