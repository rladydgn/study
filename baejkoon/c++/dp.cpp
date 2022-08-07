#include <iostream>
using namespace std;

int dp[2][2];

int main() {
	int n;
	cin >> n;
	
	dp[0][0] = 1;
	dp[0][1] = 0;
	
	for(int i=1; i<n; i++) {
		dp[1][0] = dp[0][1] + 1;
		dp[1][1] = dp[0][0] + dp[0][1];
		
		dp[0][0] = dp[1][0];
		dp[0][1] = dp[1][1];
	}
	
	cout << dp[0][0] + dp[0][1];
	
	return 0;
}
