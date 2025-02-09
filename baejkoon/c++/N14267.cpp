#include <iostream>
#include <queue> 
using namespace std;

// 상사
int boss[100001];
// 직원 칭찬 정도 
int cost[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	for(int i=1; i<=n; i++) {
		int tmp;
		cin >> tmp;
		if(tmp == -1)
			boss[i] = 0;
		else
			boss[i] = tmp;
	}
	
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		cost[a] += b;
	}
	
	for(int i=1; i<=n; i++) {
		cost[i] += cost[boss[i]];
		cout << cost[i] << " ";
	}
}
