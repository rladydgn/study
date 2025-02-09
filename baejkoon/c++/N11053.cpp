#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int per[n];
	int dp[n];
	for(int i=0; i<n; i++){
		cin >> per[i];
		dp[i] = 0;
	}
	
	dp[0] = 1;
	for(int i=0; i<n-1; i++) {
		if(dp[i] == 0)
			dp[i] = 1;
		for(int j=i+1; j<n; j++) {
			if(per[i] < per[j] && dp[j] < dp[i] + 1) {
				dp[j] = dp[i] + 1;
			}
		}
	}
	
	int answer = 0;
	for(int i=0; i<n; i++) {
		if(dp[i]>answer)
			answer = dp[i];
	}
	cout << answer;
}
