#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[32001];
int arr[32001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        arr[b] += 1;
    }

    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(arr[i] == 0)
            q.push(i);
    }

    for(int i=1; i<=n; i++) {
        int k = q.front();
        q.pop();

        cout << k << " ";

        for(int j=0; j<v[k].size(); j++) {
            arr[v[k][j]] -= 1;
            if(arr[v[k][j]] == 0)
                q.push(v[k][j]);
        }
    }

    return 0;
}