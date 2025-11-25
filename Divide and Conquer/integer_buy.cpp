#include <bits/stdc++.h>
using namespace std;

int d(long long N) {
    if (N == 0) return 0;
    string s = to_string(N);
    return s.length();
}

long long buy_integer(long long A, long long B, long long X, long long st, long long fn) {
    long long integer_buy = 0;
    if (st > fn) return 0;

    long long mid = st + (fn - st) / 2;
    long long yen = (A * mid) + (B * d(mid));

    if (X >= yen) {
        integer_buy = buy_integer(A, B, X, mid + 1, fn);
        return max(mid, integer_buy);
    }
    else {
        return buy_integer(A, B, X, st, mid - 1);
    }
}

int main() {
    long long A, B, X;
    cin >> A >> B >> X;
    long long st = 1;
    long long fn = 1000000000;
    long long res = buy_integer(A, B, X, st, fn);
    cout << res;
}