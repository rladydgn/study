#include <iostream>
#include <queue>
using namespace std;

int r, c;
int m[8][8];
int visit[8][8];
int answer;

void Work() {
	queue<pair<int, int> > q;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(m[i][j] == 2 && visit[i][j] == 0) {
				q.push({i, j});
			}
		}
	}
	
	while(!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		
		visit[p.first][p.second] = 1;
		
		if(p.first-1 >= 0 && visit[p.first-1][p.second] == 0 && m[p.first-1][p.second] != 1)
			q.push({p.first-1, p.second});
		if(p.first+1 < r && visit[p.first+1][p.second] == 0 && m[p.first+1][p.second] != 1)
			q.push({p.first+1, p.second});
		if(p.second-1 >= 0 && visit[p.first][p.second-1] == 0 && m[p.first][p.second-1] != 1)
			q.push({p.first, p.second-1});
		if(p.second+1 < c && visit[p.first][p.second+1] == 0 && m[p.first][p.second+1] != 1)
			q.push({p.first, p.second+1});
	}
				
	int cnt = 0;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(visit[i][j] == 0 && m[i][j] == 0)
				cnt++;
			visit[i][j] = 0;
		}
	}
	if(cnt > answer)
		answer = cnt;
		
}

void Dfs(int n) {
	if(n == 3) {
		Work();
		return;
	}
	
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(m[i][j] == 0) {
				m[i][j] = 1;
				Dfs(n+1);
				m[i][j] = 0;
			}
		}
	}
}
int main() {
	cin >> r >> c;
	
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cin >> m[i][j];
		}
	}
	
	Dfs(0);
	
	cout << answer;
}
