#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int v, e;
long long int answer;
int root[10001];

struct node {
    int v1;
    int v2;
    int weight;
};

bool compare(node& a, node& b) {
    if(a.weight < b.weight)
        return true;
    return false;
}

int FindParent(int a) {
    if(root[a] == a) return a;
    return root[a] = FindParent(root[a]);
}

bool SameParent(int a, int b) {
    if(FindParent(a) == FindParent(b))
        return true;
    return false;
}

void UnionParent(int a, int b) {
    a = FindParent(a);
    b = FindParent(b);
    if(a<b) root[b] = a;
    else root[a] = b;
}

int main() {
    cin >> v >> e;
    vector<node> edges;

    for(int i=0; i<e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back(node({a, b, c}));
    }

    for(int i=1; i<=v; i++)
        root[i] = i;

    sort(edges.begin(), edges.end(), compare);

    for(int i=0; i<edges.size(); i++) {
        if(SameParent(edges[i].v1, edges[i].v2)) continue;
        UnionParent(edges[i].v1, edges[i].v2);
        answer += edges[i].weight;
    }
    cout << answer;
    return 0;
}