#include <iostream>
#include <string>

using namespace std;

// 3: up, 2: left, 1: same, 0: not same
int status[1001][1001];
int dp[1001][1001];

int main() {
	string a, b;
	cin >> a >> b;
	
	for(int i=0; i<a.length(); i++) {
		for(int j=0; j<b.length(); j++) {
			if(a[i] == b[j]) {
				status[i+1][j+1] = 1;
				dp[i+1][j+1] = 1 + dp[i][j];
			}
			else if(dp[i][j+1] > dp[i+1][j]) {
				status[i+1][j+1] = 3;
				dp[i+1][j+1] = dp[i][j+1];
			}
			else {
				status[i+1][j+1] = 2;
				dp[i+1][j+1] = dp[i+1][j];
			}
		}
	}
	int max = 0;
	for(int i=0; i<=b.length(); i++) {
		if(max < dp[a.length()][i])
			max = dp[a.length()][i];
	}
	cout << max;
	
//	for(int i=0; i<=a.length(); i++) {
//		for(int j=0; j<=b.length(); j++) {
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
}
