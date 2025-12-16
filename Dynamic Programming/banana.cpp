#include <iostream>
#include <cstring>
using namespace std;

int N, K;
int grid[1000][1000];
int memo[1000][1000];

int findBanana(int r, int c, int row) {
    if (r == N-1 or c == N-1) return grid[r][c];
    if (r == N or c == N) return 0;
}

int main() {
    cin >> N;
    memset(memo, -1, sizeof(memo));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> grid[i][j];
        }
    }

    int row = N + 1;
    for (int i = N-1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cin >> grid[row][j];
        }
        row++;
    }

    cout << findBanana(0,0, 2 * N - 1) << endl;
}