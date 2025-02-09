#include <iostream>
#include <queue>

using namespace std;

int visit[100001];

int main() {
	int a, b, n, m;
	cin >> a >> b >> n >> m;
	
	queue<pair<int ,int> > q;
	q.push({0, n});
	int answer = 0;
	
	while(!q.empty()) {
		int f = q.front().first;
		int s = q.front().second;
		q.pop();
		
		if(visit[s] == 1)
			continue;
			
		if(s == m) {
			answer = f;
			break;
		}
		visit[s] = 1;

		int cal[4] = {1, a, b};
		for(int i=0; i<4; i++) {
			if(s+cal[i]<=100000 && visit[s+cal[i]] == 0)
				q.push({f+1, s+cal[i]});
			if(s-cal[i]>=0 && visit[s-cal[i]] == 0)
				q.push({f+1, s-cal[i]});
		}
		if(s*a<=100000 && visit[s*a] == 0)
			q.push({f+1, s*a});
		if(s*b<=100000 && visit[s*b] == 0)
			q.push({f+1, s*b});
	}
	
	cout << answer;
}
