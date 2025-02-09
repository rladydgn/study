#include <iostream>
#include <vector>

using namespace std;

int n, k, x;
int answer;
vector<pair<int, int> > v;

void Dfs(int idx, int cnt, int valuea, int valueb) {
	if(cnt == k) {
		if(answer < valuea*valueb)
			answer = valuea*valueb;
		return;
	}
	
	for(int i=idx; i<n; i++) {
		Dfs(i+1, cnt+1, valuea+v[i].first, valueb+v[i].second);
	}
}

int main() {
	cin >> n >> k >> x;
	for(int i=0; i<n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}
	
	Dfs(0, 0, 0, 0);
	
	cout << answer;
	
	return 0;
}
