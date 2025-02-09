#include <iostream>

using namespace std;

int t[16], p[16];
int answer;
int n;

void Dfs(int idx, int price) {
	if(answer < price)
		answer = price;
	
	for(int i=idx; i<=n; i++) {
		// 마지막날 1일인 경우 그 값도 더해줘야 하기 때문에 마지막날 +1을 제한으로 두었다. 
		if(t[i]+i <= n+1) {
			Dfs(t[i]+i, price+p[i]);
		}
	}
}

int main() {
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> t[i] >> p[i];
	
	Dfs(1, 0);
	
	cout << answer;
	return 0;
}
