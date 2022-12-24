#include <iostream>

using namespace std;

int edges[101][101];

int main() {
    int n, m, r;
    cin >> n >> m >> r;
    int item[n+1];

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i == j)
                edges[i][j] = 0;
            else
                edges[i][j] = 999999;
        }
    }

    for(int i=1; i<=n; i++)
        cin >> item[i];
    for(int i=1; i<=r; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(edges[a][b] == 0 || (edges[a][b] != 0 && edges[a][b] > c)) {
            edges[a][b] = c;
            edges[b][a] = c;
        }
    }

    for(int l=1; l<=n; l++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                edges[i][j] = min(edges[i][j], edges[i][l]+edges[l][j]);
            }
        }
    }

    int answer = 0;
    for(int i=1; i<=n; i++) {
        int s = 0;
        for(int j=1; j<=n; j++) {
            if(edges[i][j] <= m)
                s+= item[j];
        }
        if(answer < s)
            answer = s;
    }
    cout << answer;

    return 0;
}