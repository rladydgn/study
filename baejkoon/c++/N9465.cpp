#include <iostream>
using namespace std;

int prices[2][100000];
int dp[3][100000];

int max(int a, int b) {
	if(a<b)
		return b;
	return a;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	
	for(int i=0; i<t; i++) {
		int n;
		cin >> n;
		
		for(int j=0; j<2; j++) {
			for(int k=0; k<n; k++) {
				cin >> prices[j][k];
			}
		}
		
		for(int j=0; j<3; j++) {
			for(int k=0; k<n; k++) {
				dp[j][k] = 0;
			}
		}
		
		dp[0][0] = prices[0][0];
		dp[1][0] = prices[1][0];
		
		for(int j=1; j<n; j++) {
			dp[0][j] = max(dp[1][j-1], dp[2][j-1]) + prices[0][j];
			dp[1][j] = max(dp[0][j-1], dp[2][j-1]) + prices[1][j];
			dp[2][j] = max(dp[0][j-1], dp[1][j-1]);
		}
		
		int answer = max(max(dp[0][n-1], dp[1][n-1]), dp[2][n-1]);
		cout << answer << "\n";
	}
}
