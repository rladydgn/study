#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int answer[100001];
int visit[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int> > edges(n+1);
	for(int i=0; i<n-1; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	
	queue<int> q;
	q.push(1);
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		
		if(visit[node])
			continue;
			
		visit[node] = 1;
		for(int i=0; i<edges[node].size(); i++) {
			if(!answer[edges[node][i]]) {
				answer[edges[node][i]] = node;
				q.push(edges[node][i]);
			}
		}
	}
	
	for(int i=2; i<=n; i++)
		cout << answer[i] << "\n";
}
