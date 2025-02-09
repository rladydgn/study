#include <iostream>
#include <string>
using namespace std;

int tf[8];

void dfs(int i, int n, int depth, string s) {
    if(depth == 1) {
        cout << s << to_string(i) << "\n";
        return;
    }
    s += to_string(i) + " ";
    tf[i-1] = true;
    for(int k=i+1; k<=n; k++) {
        if(!tf[k-1])
            dfs(k, n, depth-1, s);
    }
    tf[i-1] = false;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        dfs(i, n, m, "");
}
