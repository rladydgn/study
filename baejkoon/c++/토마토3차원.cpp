#include <iostream>
#include <queue>

using namespace std;

struct node {
	int h;
	int r;
	int c;
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, h;
	cin >> m >> n >> h;
	int arr[h][n][m];
	queue<node> q;
	for(int i=h-1; i>=0; i--) {
		for(int j=0; j<n; j++) {
			for(int k=0; k<m; k++) {
				cin >> arr[i][j][k];
				if(arr[i][j][k] == 1)
					q.push({i, j, k});
			}
		}
	}
	
	while(!q.empty()) {
		node a = q.front();
		q.pop();
		
		// cout << a.h << " " << a.r << " " << a.c << endl;
				
		int hh[] = {1, -1, 0, 0, 0, 0};
		int rr[] = {0, 0, 1, -1, 0, 0};
		int cc[] = {0, 0, 0, 0, 1, -1};
		
		for(int i=0; i<6; i++) {
			int dh = a.h + hh[i];
			int dr = a.r + rr[i];
			int dc = a.c + cc[i];
			
			if(dh>=0 && dr>=0 && dc>=0 && dh<h && dr<n && dc<m && arr[dh][dr][dc] == 0) {
				arr[dh][dr][dc] = arr[a.h][a.r][a.c] + 1;
				q.push({dh, dr, dc});
			}
		}
	}
	int answer = 0;
	for(int i=0; i<h; i++) {
		for(int j=0; j<n; j++) {
			for(int k=0; k<m; k++) {
				if(arr[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
				if(answer < arr[i][j][k])
					answer = arr[i][j][k];
			}
		}
	}
	cout << answer-1;
	return 0;
}
