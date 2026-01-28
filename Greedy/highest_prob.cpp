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
        dist[i] = 0.0;
        visited[i] = false;
    }

    dist[source] = 1.0;
    priority_queue<pii> pq;
    pq.emplace(dist[source], source);

    while (not pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto &p : adj[u]) {
            int a = p.first;
            double w = p.second;
            double total_weight = dist[u] * w;

            if (not visited[a] and dist[a] < total_weight) {
                dist[a] = total_weight;
                parent[a] = u;
                pq.emplace(dist[a], a);
            }
        }
    }
}

void path(int destination) {
    if (dist[destination] == INF) {
        cout << "No path exist" << endl;
        return;
    }
    else {
        vector<int> route;
        int temp = destination;

        while (temp != -1) {
            route.emplace_back(temp);
            temp = parent[temp];
        }

        reverse(route.begin(), route.end());

        for (int i = 0; i < route.size(); i++) {
            cout << route[i] << (i == route.size() - 1 ? "" : " => ");
        }
        cout << "Total Distance :" << dist[destination];
    }
}

int main() {
    cin >> v >> e;
    for (int i = 1; i <= e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        if (w >=0 and w <= 1) {
            adj[a].emplace_back(b, w);
            adj[b].emplace_back(a, w);
        }
        else {
            cout << w << " should be greater equal 0 or less equal 1" << endl;
            break;
        }
    }

    dijkstra(0);
}