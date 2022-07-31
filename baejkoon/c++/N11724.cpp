#include <iostream>

using namespace std;

int edges[1001][1001];
int visit[1001];

void dfs(int node, int n) {
	if(visit[node])
		return;
	visit[node] = 1;
	
	for(int i=1; i<=n; i++) {
		if(edges[node][i] && !visit[i])
			dfs(i, n);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		edges[a][b] = 1;
		edges[b][a] = 1;
	}
	
	int answer = 0;
	
	for(int i=1; i<=n; i++) {
		if(visit[i])
			continue;
		
		dfs(i, n);
		answer++;
	}
	cout << answer;
}
