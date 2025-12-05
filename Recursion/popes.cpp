#include <bits/stdc++.h>
using namespace std;

int Y, P, max_popes, best_first, best_last;
vector<int> years;

void solve_recursive(int left, int right) {
    if (right == P) return;

    if (years[right] >= years[left] + Y) {
        solve_recursive(left + 1, right);
    } else {
        int current = right - left + 1;
        if (current > max_popes) {
            max_popes = current;
            best_first = years[left];
            best_last = years[right];
        }
        solve_recursive(left, right + 1);
    }
}

int main() {
    while (cin >> Y) {
        cin >> P;
        years.resize(P);
        for (int i = 0; i < P; ++i) {
            cin >> years[i];
        }

        max_popes = 0;
        best_first = 0;
        best_last = 0;

        solve_recursive(0, 0);

        cout << max_popes << " " << best_first << " " << best_last << "\n";
    }
    return 0;
}