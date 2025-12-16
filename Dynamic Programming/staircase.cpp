#include <iostream>
#include <vector>
using namespace std;

vector<long long> memo(505);

long long count_stairs(int n) {
    memo[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= i; j--) {
            memo[j] += memo[j-i];
        }
    }

    return memo[n] - 1;
}

int main() {
    int n;
    cin >> n;
    fill(memo.begin(), memo.end(), 0);

    cout << count_stairs(n) << endl;
}