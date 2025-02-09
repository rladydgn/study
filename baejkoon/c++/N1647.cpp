#include <iostream>
#include <queue>

using namespace std;

int parent[100001];

int findParent(int a) {
    if(a == parent[a]) return a;
    else return parent[a] = findParent(parent[a]);
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
    priority_queue<pair<int, pair<int, int>>> pq;
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({-c, {a, b}});
    }

    for(int i=1; i<=n; i++) parent[i] = i;

    int answer = 0;
    int connect = 0;
    while(!pq.empty()) {
        int weight = -pq.top().first;
        pair<int, int> nodes = pq.top().second;
        pq.pop();

        // n-2번의 유니온이 이뤄지면 중지, 집 분리됨
        if(connect == n-2) break;
        if(findParent(nodes.first) == findParent(nodes.second)) continue;

        connect++;
        answer += weight;
        unions(nodes.first, nodes.second);
    }

    cout << answer;
    return 0;
}