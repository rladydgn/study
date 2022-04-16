#include <iostream>

using namespace std;

int stair[301];
int dp[301];
int n;

void rec(int step, int now) {
	if(now < 0)
		return;
		
	//cout << now << endl; 
	
	int tmp = stair[now] + dp[now+step];
	if(tmp >= dp[now])
		dp[now] = tmp;
	else
		return;
	if(step == 2 || now-1 == 0)
		rec(1, now-1);
	rec(2, now-2);
}


int main() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> stair[i];
	}
	
	dp[n] = stair[n];
	
	rec(1, n-1);
	rec(2, n-2);
	
	cout << dp[0];
}
