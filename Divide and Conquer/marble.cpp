#include <bits/stdc++.h>
using namespace std;

int marble(vector<int> &marbles, int st, int fn, int Q) {
    int first_occur = -1;

    while (st <= fn) {
        int mid = st + (fn - st) / 2;

        if (marbles[mid] == Q) {
            first_occur = mid;
            fn = mid-1;
        }
        else if (marbles[mid] > Q) fn = mid-1;
        else st = mid+1;
    }

    return first_occur;
}

int main() {
    int N, Q;
    int case_num = 1;

    while (cin >> N >> Q && (N != 0 || Q != 0)) {
        vector<int> marbles(N);

        for (int j = 0; j < N; j++) {
            cin >> marbles[j];
        }
        sort(marbles.begin(), marbles.end());

        cout << "CASE# " << case_num++ << ":" << endl;

        for (int k = 0; k < Q; k++) {
            int q;
            cin >> q;
            int res = marble(marbles, 0, N-1, q);

            if (res == -1) {
                cout << q << " not found" << endl;
            }
            else {
                cout << q << " found at " << res+1 << endl;
            }
        }
    }

    return 0;
}