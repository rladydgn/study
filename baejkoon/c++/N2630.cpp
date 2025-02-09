#include <iostream>

using namespace std;

int arr[128][128];

int blue, white;

void Dfs(int r, int c, int n) {
    int check = arr[r][c];
    for(int i=r; i<r+n; i++) {
        for(int j=c; j<c+n; j++) {
            if(check != arr[i][j]) {
                Dfs(r, c, n/2);
                Dfs(r, (c*2+n)/2, n/2);
                Dfs((r*2+n)/2, c, n/2);
                Dfs((r*2+n)/2, (c*2+n)/2, n/2);
                return;
            }
        }
    }
    // cout << r << " " << c << " " << n << " " << check << endl;
    if(check)
        blue++;
    else
        white++;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];

    Dfs(0, 0, n);

    cout << white << "\n" << blue;
    return 0;
}