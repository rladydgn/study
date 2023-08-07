#include <iostream>

using namespace std;

int parent[1000001];

int find(int a) {
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void unions(int a, int b) {
    a = find(a);
    b = find(b);

    if(a < b) parent[b] = a;
    else parent[a] = b;
}

void check(int a, int b) {
    a = find(a);
    b = find(b);
    if(a==b) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    for(int i=0; i<=n; i++) {
        parent[i] = i;
    }

    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 0) {
            unions(b, c);
        }
        else {
            check(b, c);
        }
    }
    return 0;
}