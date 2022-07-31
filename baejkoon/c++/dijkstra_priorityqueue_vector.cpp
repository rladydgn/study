#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int paths[1001];
int visit[1001];

struct cmp {
	bool operator()(pair<int, int> &a, pair<int, int> &b) {
		return a.second > b.second;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	vector<pair<int, int> > v[1001];
	for(int i=0; i<1001; i++) {
		paths[i] = 2000000000;
	}
	
	for(int i=0; i<m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
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
		
		for(int i=0; i<v[node].size(); i++) {
			if(paths[v[node][i].first]>paths[node]+v[node][i].second) {
				paths[v[node][i].first] = paths[node] + v[node][i].second;
				pq.push(make_pair(v[node][i].first, paths[v[node][i].first]));
			}
		}
	}
	
	cout << paths[end];
	
}
