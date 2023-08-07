#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int, int>> v;
int answer = 2147483647;
int visited[10];
int n;

void dfs(int sour, int bitter, int idx) {
    for(int i=idx; i<n; i++) {
        if(visited[i] == 0) {
            answer = min(answer, abs(sour*v[i].first - (bitter+v[i].second)));
            visited[i] = 1;
            dfs(sour*v[i].first, bitter+v[i].second, i+1);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    dfs(1, 0, 0);
    cout << answer;

    return 0;
}