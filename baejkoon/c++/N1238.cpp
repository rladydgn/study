#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, x;
vector<vector<pair<int, int>>> v1(1001), v2(1001);
int arr1[1001], arr2[1001];

void dijkstra(vector<vector<pair<int, int>>>& v, int arr[]) {
    // to, value
    priority_queue<pair<int, int>> pq;
    pq.push({0, x});
    int visited[1001] = {0, };

    while(!pq.empty()) {
        int value = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(visited[node]) continue;
        visited[node] = 1;

        for(int i=0; i<v[node].size(); i++) {
            if(arr[v[node][i].first] == 0) arr[v[node][i].first] = value+v[node][i].second;
            else arr[v[node][i].first] = min(arr[v[node][i].first], value+v[node][i].second);
            pq.push({-arr[v[node][i].first], v[node][i].first});
        }
    }
}

int main() {
    cin >> n >> m >> x;
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v1[a].push_back({b, c});
        v2[b].push_back({a, c});
    }

    dijkstra(v1, arr1);
    dijkstra(v2, arr2);

    int answer = 0;
    for(int i=1; i<=1000; i++) {
        if(arr1[i] != 0 && arr2[i] != 0 && i!= x) answer = max(answer, arr1[i] + arr2[i]);
    }
    cout << answer;
    return 0;
}