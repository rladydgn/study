#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, m;
	cin >> m >> n;
	
	int tomato[n][m];
	queue<pair<int, int> > q;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> tomato[i][j];
			if(tomato[i][j] == 1) {
				q.push({i, j});
			}
		}
	}
	
	while(!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		
		// cout << r << " " << c << endl;
		q.pop();
		
		if(r+1<n && tomato[r+1][c] == 0) {
			tomato[r+1][c] = tomato[r][c] + 1;
			q.push({r+1, c});
		}
		
		if(r-1>=0 && tomato[r-1][c] == 0) {
			tomato[r-1][c] = tomato[r][c] + 1;
			q.push({r-1, c});
		}
		
		if(c+1<m && tomato[r][c+1] == 0) {
			tomato[r][c+1] = tomato[r][c] + 1;
			q.push({r, c+1});
		}
		
		if(c-1>=0 && tomato[r][c-1] == 0) {
			tomato[r][c-1] = tomato[r][c] + 1;
			q.push({r, c-1});
		}
	}
	
	int answer = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(tomato[i][j] == 0) {
				cout << -1;
				return 0;
			}
			if(answer < tomato[i][j]-1)
				answer = tomato[i][j]-1;
		}
	}

	cout << answer;
}
