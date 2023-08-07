#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> v;
int n, m;

void dfs(int cnt, int idx, string s) {
    if(cnt == m) {
        cout << s << "\n";
        return;
    }

    for(int i=idx; i<n; i++) {
        dfs(cnt+1, i+1, s+to_string(v[i])+" ");
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    dfs(0, 0, "");
}