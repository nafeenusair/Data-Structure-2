#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int v, e, blackList;
vector<pii > adj[100];
int dist[100], dist2[100], parent[100], node_weight[100];
bool visited[100], blackListed[100];

void dijkstra(int source) {
    for (int i = 1; i <= v; i++) {
        parent[i] = -1;
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    int root = source;
    dist[root] = 0;

    priority_queue<pii, vector<pii >, greater<pii > > pq;
    pq.emplace(dist[root], root);

    while (not pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto &p: adj[u]) {
            int a = p.first, w = p.second;

            if (not visited[a] and dist[a] > dist[u] + w) {
                dist[a] = dist[u] + w;
                parent[a] = u;
                pq.emplace(dist[a], a);
            }
        }
    }
}

void multiplication_dijkstra(int source) {
    for (int i = 1; i <= v; i++) {
        parent[i] = -1;
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    int root = source;
    dist[root] = 1;

    priority_queue<pii, vector<pii >, greater<pii > > pq;
    pq.emplace(dist[root], root);

    while (not pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto &p: adj[u]) {
            int a = p.first, w = p.second;

            if (not visited[a] and dist[a] > dist[u] * w) {
                dist[a] = dist[u] * w;
                parent[a] = u;
                pq.emplace(dist[a], a);
            }
        }
    }
}

void dijkstra_node(int source) {
    for (int i = 1; i <= v; i++) {
        parent[i] = -1;
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[source] = node_weight[source];

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(dist[source], source);

    while (not pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto &p : adj[u]) {
            int a = p.first, w = p.second;

            int weight = dist[u] + w + node_weight[a];

            if (not visited[a] and dist[a] > weight) {
                dist[a] = weight;
                parent[a] = u;
                pq.emplace(dist[a], a);
            }
        }
    }
}

void single_dst_dijkstra(int source, int destination) {
    for (int i = 1; i <= v; i++) {
        parent[i] = -1;
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    int root = source;
    dist[root] = 0;

    priority_queue<pii, vector<pii >, greater<pii > > pq;
    pq.emplace(dist[root], root);

    while (not pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (u == destination) {
            cout << "Target Destination Reached!" << endl;
            return;
        }

        if (visited[u]) continue;
        visited[u] = true;

        for (auto &p: adj[u]) {
            int a = p.first, w = p.second;

            if (not visited[a] and dist[a] > dist[u] + w) {
                dist[a] = dist[u] + w;
                parent[a] = u;
                pq.emplace(dist[a], a);
            }
        }
    }
}

void nodeWithBlackList(int source) {
    for (int i = 1; i <= v; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = false;
    }

    if (blackListed[source]) return;

    dist[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(dist[source], source);

    while (not pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto &p : adj[u]) {
            int a = p.first, w = p.second;

            if (blackListed[a]) continue;

            if (not visited[a] and dist[a] > dist[u] + w) {
                dist[a] = dist[u] + w;
                parent[a] = u;

                pq.emplace(dist[a], a);
            }
        }
    }
}

void secondBest(int source) {
    for (int i = 1; i <= v; i++) {
        dist[i] = INT_MAX;
        dist2[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = false;
    }

    dist[source] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(dist[source], source);

    while (not pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist2[u]) continue;

        for (auto &p : adj[u]) {
            int a = p.first, w = p.second;
            int total_w = d + w;

            if (total_w < dist[a]) {
                dist2[a] = dist[a];
                dist[a] = total_w;
                pq.emplace(dist[a], a);
                pq.emplace(dist2[a], a);
            }
            else if (total_w > dist[a] and total_w < dist2[a]) {
                dist2[a] = total_w;
                pq.emplace(dist2[a], a);
            }
        }
    }
}

void findPath(int source, int destination) {
    dijkstra(source);

    if (dist[destination] == INT_MAX) cout << "No path exists";
    else {
        vector<int> route;

        int temp = destination;
        while (temp != -1) {
            route.emplace_back(temp);
            temp = parent[temp];
        }

        reverse(route.begin(), route.end());

        cout << "Path from " << source << " to " << destination << " : ";
        for (int i = 1; i <= route.size(); i++) {
            cout << route[i] << (i == route.size() - 1 ? "" : " => ");
        }
        cout << endl << "Total Distance: " << dist[destination] << endl;
    }
}

int main() {
    cin >> v >> e;

    for (int i = 1; i <= v; i++) {
        cin >> node_weight[i];
    }

    for (int i = 1; i <= e; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }

    dijkstra(0);

    int source, destination;
    cout << "Enter start point and end : ";
    cin >> source >> destination;
    findPath(source, destination);

    cin >> blackList;
    for (int i = 1; i <= blackList; i++) {
        int node;
        cin >> node;
        blackListed[node] = true;
    }
    nodeWithBlackList(0);
}
