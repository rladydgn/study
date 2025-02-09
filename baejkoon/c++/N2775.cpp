#include <iostream>

using namespace std;

int arr[15][15];

int main() {
    int t;
    cin >> t;
    for(int i=1; i<=14; i++)
        arr[0][i] = i;
    
    for(int i=1; i<=14; i++) {
        for(int j=1; j<=14; j++) {
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }

    for(int i=0; i<t; i++) {
        int k, n;
        cin >> k >> n;
        cout << arr[k][n] << "\n";
    }
    return 0;
}