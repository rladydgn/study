#include <iostream>

using namespace std;

int arr[301][301];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            int t;
            cin >> t;
            arr[i][j] = t + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << arr[c][d]+arr[a-1][b-1]-arr[c][b-1]-arr[a-1][d] << "\n";
    }
    return 0;
}