#include <iostream>

using namespace std;

int dp[10001];

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    for(int i=0; i<n; i++) {
        for(int j=1; j<=k; j++) {
            if(j == arr[i]) dp[j] += 1;

            if(j-arr[i]>0) {
                dp[j] = dp[j] + dp[j-arr[i]];
            }
        }
    }
    cout << dp[k];

    return 0;
}