#include <iostream>
#include <string>
#include <queue>

using namespace std;

// int visited[100][100];

struct pos {
	int x;
	int y;
};

int main() {
	int n, m;
	cin >> n >> m;
	int arr[n][m];
	for(int i=0; i<n; i++) {
		string tmp;
		cin >> tmp;
		for(int j=0; j<tmp.size(); j++) {
			arr[i][j] = tmp[j] - '0';
		}
	}
	
	queue<pair<pos, int>> q;
	q.push({{0, 0}, 1});
	while(!q.empty()) {
		pos a = q.front().first;
		int b = q.front().second;
		q.pop();
		
		if(a.x == n-1 && a.y == m-1) {
			cout << b;
			return 0;
		}
		
		if(arr[a.x][a.y] == 0) continue;
		arr[a.x][a.y] = 0;
		
		// if(visited[a.x][a.y] == 1) continue;
		// visited[a.x][a.y] = 1;
		
		int r[] = {0, 0, 1, -1};
		int c[] = {1, -1, 0, 0};
		
		for(int j=0; j<4; j++) {
			int dr = a.x+r[j];
			int dc = a.y+c[j];
			
			if(dr >= 0 && dr < n && dc >= 0 && dc < m && arr[dr][dc] == 1) {
				q.push({{dr, dc}, b+1});
			}
		}
	}
	return 0;
}
