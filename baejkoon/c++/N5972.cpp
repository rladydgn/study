#include <iostream>
#include <queue>

using namespace std;

// 여물, 목적지
vector<pair<int, int>> v[50001];
int visited[50001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }

    priority_queue<pair<int, int>> pq;
    for(int i=0; i<v[1].size(); i++) {
        pq.push({-v[1][i].first, v[1][i].second});
    }
    visited[1] = 1;

    while(!pq.empty()) {
        int weight = -pq.top().first;
        int node = pq.top().second;

        pq.pop();

        if(visited[node] == 1) continue;
        if(node == n) {
            cout << weight;
            return 0;
        }
        
        visited[node] = 1;
        for(int i=0; i<v[node].size(); i++) {
            if(visited[v[node][i].second] == 0) {
                pq.push({-(weight+v[node][i].first), v[node][i].second});
            }
        }
    }

    return 0;
}