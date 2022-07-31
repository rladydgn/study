#include <iostream>
#include <queue>
using namespace std;

int edges[1001][1001];
int paths[1001];
int visit[1001];

struct cmp {
	bool operator()(pair<int, int> &a, pair<int, int> &b) {
		return a.second > b.second;
	}
};

int main() {
	
	for(int i=0; i<1001; i++) {
		paths[i] = 2000000000;
		for(int j=0; j<1001; j++) {
			edges[i][j] = 2000000000;
		}
	}
	
	int n, m;
	cin >> n >> m;
	
	for(int i=0; i<m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if(edges[a][b] > c)
			edges[a][b] = c;
	}
	
	// index, size
	priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
	
	int start, end;
	cin >> start >> end;
	
	paths[start] = 0;
	pq.push(make_pair(start, 0));
	
	while(true) {
		if(pq.empty())
			break;
			
		int node = pq.top().first;
		pq.pop();
		
		if(visit[node])
			continue;
			
		visit[node] = 1;
		
		for(int i=1; i<=n; i++) {
			if(paths[i]>paths[node]+edges[node][i]) {
				paths[i] = paths[node] + edges[node][i];
				pq.push(make_pair(i, paths[i]));
			}
		}
	}
	
	cout << paths[end];
	
}
