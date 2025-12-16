#include <iostream>
#include <cstring>
using namespace std;

int N, K;
int grid[1000][1000];
long long memo[1000][1000];

long long maxBanana_count(int r, int c, int t_r) {
    if (c < 1) return 0;
    if (r > t_r) return 0;

    int current_width;
    if (r <= N) current_width = r;
    else current_width = 2 * N - r;
    if (current_width < c) return 0;

    if (r == t_r and c == 1) return grid[r][c];
    if (memo[r][c] != -1) return memo[r][c];

    long long banana = 0;

    if (r < N) {
        banana = grid[r][c] + max(maxBanana_count(r+1, c, t_r), maxBanana_count(r+1, c+1, t_r));
    }
    else {
        banana = grid[r][c] + max(maxBanana_count(r+1, c, t_r), maxBanana_count(r+1, c-1, t_r));
    }

    return memo[r][c] = banana;
}

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
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

        cout << "Case " << i << ": " << maxBanana_count(1,1, 2 * N - 1) << endl;
    }
}