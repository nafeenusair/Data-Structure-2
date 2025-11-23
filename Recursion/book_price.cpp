/*
 exact sum
*/

#include <bits/stdc++.h>
using namespace std;

int best_i, best_j;

void recommended(vector<int> &prices, int M, int st, int fn){
    if (st >= fn) return;

    int current_sum = prices[st] + prices[fn];

    if (current_sum > M) recommended(prices, M, st, fn - 1);
    else if (current_sum < M) recommended(prices, M, st+1, fn);
    else {
        best_i = prices[st];
        best_j = prices[fn];

        recommended(prices, M, st+1, fn-1);
    }
} 

int main() {
    int N, M; //N = Total available books, M = Money

    while(cin >> N){
        vector<int> prices(N); //all book prices

        for(int i = 0; i < N; i++){
            cin >> prices[i];
        }

        cin >> M;

        sort(prices.begin(), prices.end());
        best_i = -1; best_j = -1;
        recommended(prices, M, 0, N-1);
        cout << "Peter should buy books whose prices are " << best_i << " and " << best_j << "." << endl << endl;

        for (int i = 0; i < N; i++) {
            prices[i] = 0;
        }
    }

    return 0;
}