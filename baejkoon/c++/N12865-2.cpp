#include <iostream>
using namespace std;

int dp[101][100001];

int main() {
	int n, weight;
	cin >> n >> weight;
	
	for(int i=1; i<=n; i++) {
		// a�� ���� b �� ��ġ 
		int a, b;
		cin >> a >> b;
		for(int j=1; j<=weight; j++) {
			if(j >= a) {
				dp[i][j] = max(dp[i-1][j-a]+b, dp[i-1][j]);
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	cout << dp[n][weight];
}
