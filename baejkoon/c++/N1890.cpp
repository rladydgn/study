#include <iostream>

using namespace std;

long long int dp[100][100];

int main() {
    int n;
    cin >> n;
    int arr[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    dp[0][0] = 1;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(dp[i][j] && arr[i][j]) {
                if(i+arr[i][j]<n) {
                    dp[i+arr[i][j]][j] += dp[i][j];
                }
                if(j+arr[i][j]<n) {
                    dp[i][j+arr[i][j]] += dp[i][j];
                }
            }
        }
    }
    cout << dp[n-1][n-1];
    return 0;
}