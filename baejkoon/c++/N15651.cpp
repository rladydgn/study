#include <iostream>
#include <string>
using namespace std;

void dfs(int i, int n, int depth, string s) {
    if(depth == 1) {
        cout << s << to_string(i) << "\n";
        return;
    }

    s += to_string(i) + " ";

    for(int k=1; k<=n; k++)
        dfs(k, n, depth-1, s);
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++)
        dfs(i, n, m, "");
}
