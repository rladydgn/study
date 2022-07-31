#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visit[20001];
int answer[20001];

struct cmp {
	bool operator() (pair<int, int> &a, pair<int, int> &b) {
		return a.first > b.first;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int v, e ,start;
	cin >> v >> e >> start;
	
	vector<pair<int, int> > edges[v+1];
	
	for(int i=0; i<e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back(make_pair(b, c));
	}
	
	priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
	pq.push(make_pair(0, start));
	
	while(!pq.empty()) {
		
		int node = pq.top().second;
		pq.pop();
		if(visit[node])
			continue;
		visit[node] = 1;
		
		for(int i=0; i<edges[node].size(); i++) {
			if(!answer[edges[node][i].first] || answer[edges[node][i].first] > answer[node]+edges[node][i].second) {
				answer[edges[node][i].first] = answer[node]+edges[node][i].second;
				pq.push(make_pair(answer[edges[node][i].first], edges[node][i].first));
			}
		}
	}
	
	answer[start] = 0;
	for(int i=1; i<=v; i++) {
		if(start != i && !answer[i])
			cout << "INF" << "\n";
		else
			cout << answer[i] << "\n";
	}
}


//#include <iostream>
//#include <queue>
//#include <vector>
//using namespace std;
//
//int paths[20001];
//int visit[20001];
//
//struct cmp {
//	bool operator()(pair<int, int> &a, pair<int, int> &b) {
//		return a.second > b.second;
//	}
//};
//
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	
//	int n, m, start;
//	cin >> n >> m >> start;
//	
//	vector<pair<int, int> > v[n+1];
//	for(int i=0; i<n+1; i++) {
//		paths[i] = 2000000000;
//	}
//	
//	for(int i=0; i<m; i++) {
//		int a, b, c;
//		cin >> a >> b >> c;
//		v[a].push_back(make_pair(b, c));
//	}
//	
//	// index, size
//	priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
//	
//	paths[start] = 0;
//	pq.push(make_pair(start, 0));
//	
//	while(true) {
//		if(pq.empty())
//			break;
//			
//		int node = pq.top().first;
//		pq.pop();
//		
//		if(visit[node])
//			continue;
//			
//		visit[node] = 1;
//		
//		for(int i=0; i<v[node].size(); i++) {
//			if(paths[v[node][i].first]>paths[node]+v[node][i].second) {
//				paths[v[node][i].first] = paths[node] + v[node][i].second;
//				pq.push(make_pair(v[node][i].first, paths[v[node][i].first]));
//			}
//		}
//	}
//	
//	for(int i=1; i<=n; i++) {
//		if(paths[i] == 2000000000)
//			cout << "INF" << "\n";
//		else
//			cout << paths[i] << "\n";
//	}
//	
//}
