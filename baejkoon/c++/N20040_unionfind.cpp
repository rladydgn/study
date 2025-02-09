#include <iostream>

using namespace std;

int parent[500000];

int findParent(int a) {
    if(parent[a] == a) return a;
    return parent[a] = findParent(parent[a]);
}

void unions(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if(a<b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        parent[i] = i;
    }
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        if(findParent(a) == findParent(b)) {
            cout << i+1;
            return 0;
        }
        unions(a, b);
    }
    cout << 0;
    return 0;
}