#include <iostream>
using namespace std;

int dp[100001];

int main() {
	int n, weight;
	cin >> n >> weight;
	
	for(int i=1; i<=n; i++) {
		// a�� ���� b �� ��ġ 
		int a, b;
		cin >> a >> b;
		for(int j=weight; j>=a; j--) {
			if(dp[j-a]+b > dp[j])
				dp[j] = dp[j-a] + b;
		}
	}
	
	cout << dp[weight];
}
