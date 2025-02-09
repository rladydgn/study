#include <iostream>
#include <queue>

using namespace std;

int n, m, v;

int edges[1001][1001];
int visited[1001];

void Dfs(int v) {
	cout << v << " ";
	
	visited[v] = 1;
	
	for(int i=1; i<=n; i++) {
		if(edges[v][i] != 0 && visited[i] == 0) {
			Dfs(i);
		}
	}
}

int main() {
	cin >> n >> m >> v;
	
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		edges[a][b] = 1;
		edges[b][a] = 1;
	}
	
	Dfs(v);
	cout << "\n";
	for(int i=1; i<=n; i++)
		visited[i] = 0;
		
	queue<int> q;
	q.push(v);
	
	while(!q.empty()) {
		int a = q.front();
		q.pop();
		
		if(visited[a] == 1) continue;
		
		visited[a] = 1;
		cout << a << " ";
		
		for(int i=1; i<=n; i++) {
			if(visited[i] == 0 && edges[a][i] != 0)
				q.push(i);
		}
	}
	return 0;
}
