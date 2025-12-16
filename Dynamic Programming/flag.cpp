#include <iostream>
#include <vector>
using namespace std;

vector<long long> memo(1000);

long long countFlag(int N) {
    if (N == 0) return 0;
    if (N <= 2) return 2;

    if (memo[N] != -1) return memo[N];

    memo[N] = countFlag(N-1) + countFlag(N-2);

    return memo[N];
}

int main() {
    int N;
    cin >> N;
    memo.assign(1000, -1);

    cout << countFlag(N) << endl;
    return 0;
}
