#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[n];
	int dp[n];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}
	
	int answer = 0;
	for(int i=0; i<n; i++) {
		int m = 0;
		for(int j=0; j<i; j++) {
			if(arr[j] < arr[i] && dp[j] > m)
				m = dp[j];
		}
		dp[i] += m;
		if(answer < dp[i])
			answer = dp[i];
	}
	
	cout << answer;
	return 0;
}
