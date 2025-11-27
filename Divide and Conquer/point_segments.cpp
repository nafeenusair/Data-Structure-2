#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N, Q;
        cin >> N >> Q;
        vector<int> arr(N);

        for (int j = 0; j < N; j++) {
            cin >> arr[j];
        }

        cout << "Case " << i+1 << ":" << endl;
        for (int k = 0; k < Q; k++) {
            int a, b;
            cin >> a >> b;

            auto low_it = lower_bound(arr.begin(), arr.end(), a);
            auto up_it = upper_bound(arr.begin(), arr.end(), b);
            int count = up_it - low_it;

            cout << count << endl;
        }
    }

    return 0;
}