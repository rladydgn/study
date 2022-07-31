#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

pair<int, int> w_p[101];
int answer;
int visit[101];
int n, max_weight;
map<int, int> memo;

void Dfs(int now_weight, int price, int idx) {
	visit[idx] = 1;
	now_weight += w_p[idx].first;
	price += w_p[idx].second;
	
	if(memo[now_weight] >= price || now_weight > max_weight) {
		visit[idx] = 0;
		return;
	}
	
	memo[now_weight] = price;
	
	// cout << now_weight << " " << price << endl;
	
	if(answer < price)
		answer = price;
	
	for(int i=0; i<n; i++) {
		if(!visit[i] && now_weight+w_p[i].first <= max_weight) {
			Dfs(now_weight, price, i);
		}
	}
	visit[idx] = 0;
}

int main() {
	cin >> n >> max_weight;
	
	for(int i=0; i<n; i++) {
		int a, b;
		cin >> a >> b;
		w_p[i] = make_pair(a, b);
	}
	
	sort(w_p, w_p + n);
	
	for(int i=0; i<n; i++) {
		Dfs(0, 0, i);
	}
	cout << answer;
	
	return 0;
}
