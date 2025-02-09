#include <iostream>
#include <string> 

using namespace std;

int n, m;
int map[1000][1000];
int visit[1000][1000];
int answer = 99999999;

// row, column, times, wall broke record
void Dfs(int r, int c, int t, int broken) {
	if(r == n-1 && c == m-1) {
		if(answer > t)
			answer = t;
	}
	
	int x[4] = {0, 0, 1, -1};
	int y[4] = {1, -1, 0, 0};
	
	for(int i=0; i<4; i++) {
		int a = r + x[i];
		int b = c + y[i];
		if(a >= 0 && a < n && b >= 0 && b < m && visit[a][b] == 0) {
			visit[a][b] = 1;
			if(map[a][b] == 1 && broken == 0)
				Dfs(a, b, t+1, 1);
			else if(map[a][b] == 0)
				Dfs(a, b, t+1, broken);
			visit[a][b] = 0;
		} 
	}
}

int main() {
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		for(int j=0; j<m; j++) {
			map[i][j] = s[j] - '0';
		}
	}
	visit[0][0] = 1;
	Dfs(0, 0, 1, 0);
	
	if(answer == 99999999)
		answer = -1;
	
	cout << answer;
}
