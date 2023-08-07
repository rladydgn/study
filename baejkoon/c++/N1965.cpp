#include <iostream>

using namespace std;

int dp[1000];

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    int answer = 0;
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j]+1);
                if(dp[i]>answer) answer = dp[i];
            }
        }
    }
    cout << answer+1;
    return 0;
}