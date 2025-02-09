#include <iostream>
#include <vector>

using namespace std;

int answer[100001];
int visited[100001];
int n, r, q;
vector<int> edges[100001];

void Dfs(int node) {
    visited[node] = 1;
    answer[node] = 1;

    // 자신의 자식 노드의 서브트리들의 개수의 합
    for(int i=0; i<edges[node].size(); i++) {
        if(visited[edges[node][i]] == 0) {
            Dfs(edges[node][i]);
            answer[node] += answer[edges[node][i]];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> r >> q;
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    Dfs(r);
    for(int i=0; i<q; i++) {
        int a;
        cin >> a;
        cout << answer[a] << "\n";
    }
    return 0;
}