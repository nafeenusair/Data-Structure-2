#include <iostream>
#include <algorithm>
using namespace std;

long long grid[25][3];
long long cost[25][3];
int N;

long long color_cost() {
    grid[0][0] = cost[0][0];
    grid[0][1] = cost[0][1];
    grid[0][2] = cost[0][2];

    for (int i = 1; i < N; i++) {
        grid[i][0] = cost[i][0] + min(grid[i-1][1], grid[i-1][2]);
        grid[i][1] = cost[i][1] + min(grid[i-1][0], grid[i-1][2]);
        grid[i][2] = cost[i][2] + min(grid[i-1][0], grid[i-1][1]);
    }

    long long ans = min(grid[N-1][0], min(grid[N-1][1], grid[N-1][2]));

    return ans;
}

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        cin >> N;

        for (int j = 0; j < N; j++) {
            cin >> cost[j][0] >> cost[j][1] >> cost[j][2];
        }

        cout << "Case " << i << ": " << color_cost() << endl;
    }

    return 0;
}