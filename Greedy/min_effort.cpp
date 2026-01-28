#include <bits/stdc++.h>
#define pii pair<int, double>
#define INF INT_MAX
using namespace std;

int v, e;
vector<pii> adj[1000];
int parent[1000];
double dist[1000];
bool visited[1000];

void dijkstra(int source) {
    for (int i = 1; i <= v; i++) {
        parent[i] = -1;
        dist[i] = INF;
        visited[i] = false;
    }

    dist[source] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(dist[source], source);

    while (not pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto &p: adj[u]) {
            int a = p.first, w = p.second;
            int curr = max(dist[u], static_cast<double>(w));

            if (not visited[a] and dist[a] > curr) {
                dist[a] = curr;
                parent[a] = u;
                pq.emplace(dist[a], a);
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
        adj[b].emplace_back(a, w);
    }

    dijkstra(0);
}