#include <iostream>
#include <string>
using namespace std;

bool tf[8];

void dfs(int i,int n, int depth, string s) {

    if(depth == 1) {
        cout << s << to_string(i) << " \n";
        return;
    }
    s += to_string(i) + " ";
    tf[i-1] = true;
    for(int k=1; k<=n; k++) {
        if(!tf[k-1])
            dfs(k, n, depth-1, s);
    }
    tf[i-1] = false;
    return;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        dfs(i, n, m, "");
}
