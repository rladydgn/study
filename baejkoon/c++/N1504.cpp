#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// to, weight
vector<pair<int, int>> v[801];

int sp(int start, int end) {
    int visited[801] = {0, };
    priority_queue<pair<int, int>> pq;
    visited[start] = 1;

    if(start == end) return 0;
    for(int i=0; i<v[start].size(); i++) {
        pq.push({-v[start][i].second, v[start][i].first});
    }

    while(!pq.empty()) {
        int weight = -pq.top().first;
        int node = pq.top().second;
        visited[node] = 1;

        pq.pop();

        if(node == end) {
            return weight;
        }

        for(int i=0; i<v[node].size(); i++) {
            if(!visited[v[node][i].first]) {
                pq.push({-(weight+v[node][i].second), v[node][i].first});
            }
        }
    }
    return -1;
}

int main() {
    int n, e;
    cin >> n >> e;
    for(int i=0; i<e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    int m1, m2;
    cin >> m1 >> m2;
    int answer = 0;
    int a, b, c, d, f;
    a = sp(1, m1);
    b = sp(1, m2);
    c = sp(m2, n);
    d = sp(m1, n);
    f = sp(m1, m2);

    if(a == -1 || b == -1 || c == -1 || d == -1 || f == -1) {
        cout << -1;
        return 0;
    }
    
    answer = min(a+c, b+d) + f;
    cout << answer;
    return 0;
}