#include <iostream>

using namespace std;

int n;
int stairs[301];
// 2ĭ ���� - 0, 1ĭ - ���� ��ŭ 
int dp[301][2];

int main() {
	cin >> n;
	
	for(int i=1; i<=n; i++) {
		cin >> stairs[i];
	}
	
	dp[1][0] = stairs[1];
	dp[2][0] = stairs[1] + stairs[2];
	dp[2][1] = stairs[2];
	
	for(int i=3; i<=n; i++) {
		dp[i][0] = dp[i-1][1] + stairs[i];
		dp[i][1] = max(dp[i-2][0], dp[i-2][1]) + stairs[i];
			
	}
	
	cout << max(dp[n][0], dp[n][1]);
}
