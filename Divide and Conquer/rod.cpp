#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
    double L, n, C;
    cin >> L >> n >> C;

    double L_prime = (1.0 + n * C) * L;

    if (abs(L_prime - L) < 1e-9) {
        cout << "Case " << t << ": " << fixed << setprecision(10) << 0.0 << endl;
        return;
    }

    double low = 0.0;
    double high = M_PI / 2.0;
    double alpha = 0.0;

    double target_ratio = L_prime / L;

    for (int i = 0; i < 60; i++) {
        double mid = (low + high) / 2.0;
        double calculated_ratio = mid / sin(mid);

        if (calculated_ratio > target_ratio) {
            high = mid;
        } else {
            low = mid;
        }
    }

    alpha = low;

    double R = (L / 2.0) / sin(alpha);
    double h = R * (1.0 - cos(alpha));

    cout << "Case " << t << ": " << fixed << setprecision(10) << h << endl;
}

int main() {
    int T;
    if (cin >> T) {
        for (int i = 1; i <= T; i++) {
            solve(i);
        }
    }
    return 0;
}