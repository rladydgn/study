#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> v[1001];
int visited[1001];

void cleanv() {
    for(int i=0; i<1001; i++)
        visited[i] = 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    for(int i=0; i<m; i++) {
        int w, e;
        cin >> w >> e;
        queue<pair<int, int>> q;
        q.push({w, 0});
        cleanv();
        visited[w] = 1;
        while(!q.empty()) {
            int weight = q.front().second;
            int to = q.front().first;

            q.pop();

            if(to == e) {
                cout << weight << "\n";
                break;
            }

            for(int j=0; j<v[to].size(); j++) {
                if(visited[v[to][j].first] == 0) {
                    visited[v[to][j].first] = 1;
                    q.push({v[to][j].first, weight+v[to][j].second});
                }
            }
        }
    }
}