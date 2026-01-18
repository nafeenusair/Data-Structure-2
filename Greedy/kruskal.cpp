#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int a, b, w;

    Edge() {
        a = 0, b = 0, w = 0;
    }

    Edge(int a, int b, int w) {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

int v, e;
Edge edgeList[101];
int tree_id[101];
vector<Edge> taken;

bool cmp(Edge e1, Edge e2) {
    return e1.w < e2.w;
}

int kruskal() {
    for (int i = 0; i <= v; i++) tree_id[i] = i;
    sort(edgeList, edgeList+e, cmp);
    int total = 0;

    for (int i = 0; i < e; i++) {
        int a = edgeList[i].a;
        int b = edgeList[i].b;
        int w = edgeList[i].w;

        if (tree_id[a] != tree_id[b]) {
            total += w;
            taken.push_back(edgeList[i]);
            int temp = tree_id[a];
            for (int j = 1; j <= e; j++) {
                if (tree_id[j] == temp) tree_id[j] = tree_id[b];
            }
        }
    }

    return total;
}

int main() {
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edgeList[i] = Edge(a, b, w);
    }

    cout << kruskal();
}