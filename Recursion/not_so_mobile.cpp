#include <bits/stdc++.h>
using namespace std;

int solve(bool &isBalanced) {
    int Wl, Dl, Wr, Dr;
    cin >> Wl >> Dl >> Wr >> Dr;

    if (Wl == 0) {
        Wl = solve(isBalanced);
    }

    if (Wr == 0) {
        Wr = solve(isBalanced);
    }

    if (Wl * Dl != Wr * Dr) {
        isBalanced = false;
    }

    return Wl + Wr;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        bool isBalanced = true;
        solve(isBalanced);

        if (isBalanced) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

        if (T > 0) {
            cout << endl;
        }
    }

    return 0;
}