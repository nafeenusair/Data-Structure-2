#include <bits/stdc++.h>
#define pii pair<int, int>
#define inf INT_MAX
using namespace std;

int numV, numE;
vector<pii> adj[100];
int parent[100], key[100];
bool tree[100];

int prim(int uBlock = -1, int vBlock = -1) {
    for (int i = 1; i <= numV; i++) {
        key[i] = inf;
        tree[i] = false;
    }

    int root = 1;
    parent[root] = -1;
    key[root] = 0;

    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.emplace(key[root], root);

    int currentNode = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (tree[u]) continue;
        tree[u] = true;
        currentNode++;

        for (pii p : adj[u]) {
            int a = p.first, w = p.second;

            if (uBlock == a and vBlock == u or uBlock == u and vBlock == a) continue;

            if (not tree[a] and w < key[a]) {
                key[a] = w;
                parent[a] = u;
                pq.emplace(key[a], a);
            }
        }
    }

    if (currentNode < numV) return inf;

    int sum = 0;
    for (int i = 1; i <= numV; i++) {
        if (key[i] != inf) sum += key[i];
    }

    return sum;
}

void printEdges() {
    for (int i = 1; i <= numV; i++) {
        if (parent[i] != 0 and parent[i] != -1 and key[i] != inf) {
            cout << parent[i] << " - " << i << " : " << key[i] << endl;
        }
    }
}

bool uniqueness(){
    for (int i = 1; i <= numV; i++) {
        if (parent[i] == -1) continue;

        for (pii v : adj[i]) {
            int u = v.first, w = v.second;

            if (w == key[i] and u != parent[i]) {
                return false;
            }
        }
    }

    return true;
}

int secondMst(int best) {
    vector<pii> edgeMST;
    for (int i = 1; i < numV; i++) {
        if (parent[i] != -1) edgeMST.emplace_back(parent[i], i);
    }

    int secondBest = inf;

    for (pii a : edgeMST) {
        int res = prim(a.first, a.second);
        if (res >= best) secondBest = min(secondBest, res);
    }

    return secondBest;
}

int main() {
    cin >> numV >> numE;
    for (int i = 0; i < numE; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    int sum = prim();
    bool isUnique = uniqueness();
    int secondBest = secondMst(sum);

    cout << "Sum: " << sum << endl;
    printEdges();


    if (isUnique == true) cout << "Unique";
    else cout << "Not Unique";

    if (secondBest == inf) cout << "There is no second best MST";
    else cout << "Second Best Sum: " << secondBest;
}