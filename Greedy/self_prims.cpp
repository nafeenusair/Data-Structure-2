#include <bits/stdc++.h>
#define pii pair<int, int>
#define inf INT_MAX
#define neg_inf INT_MIN
using namespace std;

int v, e, parent[100], key[100];
vector<pii> adj[100];
bool tree[100];

int prims(int u_block = -1, int v_block = -1) {
    for (int i = 1; i <= v; i++) {
        key[i] = inf;
        tree[i] = false;
    }

    int root = 1;
    parent[root] = -1;
    key[root] = 0;

    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.emplace(key[root], root);

    int currentNode = 0;
    while (not pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (tree[u]) continue;
        tree[u] = true;
        currentNode++;

        for (pii p : adj[u]) {
            int a = p.first, w = p.second;

            if (u_block == a and v_block == u or u_block == u and v_block == a) continue;

            if (not tree[a] and w < key[a]) {
                key[a] = w;
                parent[a] = u;
                pq.emplace(key[a], a);
            }
        }
    }

    if (currentNode < v) return inf;

    int sum = 0;
    for (int i = 1; i <= v; i++) {
        if (key[i] != inf) sum += key[i];
    }

    return sum;
}

int max_prims() {
    int new_key[100];
    int new_parent[100];
    bool new_tree[100];

    for (int i = 1; i <= v; i++) {
        new_key[i] = neg_inf;
        new_tree[i] = false;
    }

    int root = 1;
    new_key[root] = 0;
    parent[root] = -1;

    priority_queue<pii> pq;
    pq.emplace(new_key[root], root);

    while (not pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (tree[u]) continue;
        tree[u] = true;

        for (pii p : adj[u]) {
            int a = p.first, b = p.second;

            if (not tree[a] and key[a] < b) {
                key[a] = b;
                parent[a] = u;
                pq.emplace(new_key[a], a);
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= v; i++) {
        if (new_key[i] != neg_inf) sum += new_key[i];
    }

    return sum;
}

void printEdge() {
    for (int i = 1; i <= v; i++) {
        if (parent[i] != -1 and parent[i] != 0 and key[i] != inf) {
            cout << parent[i] << " - " << i << " : " << key[i];
        }
    }
}

bool isUnique() {
    for (int i = 1; i <= v; i++) {
        if (parent[i] == -1) continue;

        for (pii p : adj[i]) {
            int a = p.first, w = p.second;

            if (key[i] == w and parent[i] != a) return false;
        }
    }

    return true;
}

int secondBest(int best) {
    vector<pii> edgeMST;
    for (int i = 1; i < v; i++) {
        if (parent[i] != -1) edgeMST.emplace_back(parent[i], i);
    }

    int secondBest = inf;
    for (pii p : edgeMST) {
        int a = p.first, b = p.second;
        int res = prims(a, b);

        if (res >= best) secondBest = min(res, secondBest);
    }

    return secondBest;
}

int main() {
    cin >> v >> e;
    for (int i = 1 ; i <= e; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }
}