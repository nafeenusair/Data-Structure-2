#include <bits/stdc++.h>
#define pii pair<int, int>
#define triplet tuple<int, int, int>
using namespace std;

int v, e;
vector<pii> adj[100];
int parent[100][100];
int dist[100][100];

void dijkstra(int source, int K) {
    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            dist[i][j] = INT_MAX;
            parent[i][j] = -1;
        }
    }

    dist[source][0] = 0;
    priority_queue<triplet, vector<triplet>, greater<triplet>> pq;
    pq.emplace(0, source, 0);

    while (not pq.empty()) {
        int c, n, e;
        tie(c, n, e) = pq.top();
        pq.pop();

        if (e <= K) {
            for (auto &p : adj[n]) {
                int a = p.first;
                int w = p.second;

                if (dist[a][e+1] > c + w) {
                    dist[a][e+1] = c + w;
                    parent[a][e+1] = n;
                    pq.emplace(dist[a][e+1], a, e+1);
                }
            }
        }
    }
}

int main() {
    cin >> v >> e;
    for (int i = 1; i <= e; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        adj[a].emplace_back(b, w);
    }

    int src, dst, K;
    cin >> src >> dst >> K;
    dijkstra(src, K);

    int ans = INT_MAX;
    for (int i = 0; i <= K+1; i++) {
        ans = min(ans, dst[dst][i]);
    }
}