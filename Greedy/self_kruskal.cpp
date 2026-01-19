#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int v, e, w;
    bool mst;
    Edge() {
        v = 0, e = 0, w = 0, mst = false;
    }

    Edge(int v, int e, int w) {
        this->v = v;
        this->e = e;
        this->w = w;
        this->mst = false;
    }
};

int v, e;
Edge edgeList[100];
int tree_id[100];
vector<Edge> taken;

int cmp(Edge e1, Edge e2) {
    return e1.w < e2.w;
}

int kruskal() {
    for (int i = 0; i < v; i++) {
        tree_id[i] = i;
    }

    sort(edgeList, edgeList + e, cmp);

    int total = 0;
    for (int i = 0; i < e; i++) {
        int a = edgeList[i].v;
        int b = edgeList[i].e;
        int w = edgeList[i].w;

        if (tree_id[a] != tree_id[b]) {
            total += w;
            edgeList[i].mst = true;
            taken.push_back(edgeList[i]);
            int temp = tree_id[a];
            for (int j = 0; j < v; j++) {
                if (tree_id[j] == temp) tree_id[j] = tree_id[b];
            }
        }
    }

    return total;
}

void printEdge() {
    for (auto i : edgeList) {
        int a = i.v;
        int b = i.e;
        int w = i.w;

        cout << a << " - " << b << " : " << w << endl;
    }
}

bool uniqueness(int weight) {
    int tree[100];
    for (int i = 0; i < taken.size(); i++) {
        for (int j = 0; j <= v; j++) tree[j] = j;

        int currentW = 0, edgeUsed = 0;

        for (int k = 0; k < e; k++) {
            if (edgeList[k].v == taken[i].v and edgeList[k].e == taken[i].e and edgeList[k].w == taken[i].w) continue;

            int a = edgeList[k].v;
            int e = edgeList[k].e;
            int w = edgeList[k].w;

            if (tree[a] != tree[e]) {
                currentW += w;
                int temp = tree[a];
                for (int x = 0; x < v; x++) {
                    if (tree[x] == temp) tree[x] = tree[e];
                }
                edgeUsed++;
            }
        }

        if (edgeUsed == v-1 and weight == currentW) return false;
    }

    return true;
}

int main() {
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edgeList[i] = Edge(a, b, w);
    }
}



