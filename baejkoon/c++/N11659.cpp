#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int cum[n+1], arr[n+1];
    cum[0] = 0;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        cum[i] = arr[i] + cum[i-1];
    }

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        cout << cum[b] - cum[a-1] << "\n";
    }
    return 0;
}