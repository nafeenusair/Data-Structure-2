#include <bits/stdc++.h>
using namespace std;

constexpr int max_amount = 30005;
constexpr int INF = 1000000;
int memo[max_amount];

void exact_change(const int cents[], int N, int P) {
    for (int i = 0; i < max_amount; i++) memo[i] = INF;
    memo[0] = 0;

    for (int i = 0; i < N; i++) {
        int coin = cents[i];

        for (int j = max_amount - 1; j >= coin; j--) {
            if (memo[j - coin] != INF) {
                memo[j] = min(memo[j], memo[j - coin] + 1);
            }
        }
    }

    for (int k = P; k < max_amount; k++) {
        if (memo[k] != INF) {
            cout << k << " " << memo[k] << endl;
            return;
        }
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int P, N;
        cin >> P >> N;
        int cents[105];

        for (int i = 0; i < N; i++) {
            cin >> cents[i];
        }

        exact_change(cents, N, P);
    }

    return 0;
}