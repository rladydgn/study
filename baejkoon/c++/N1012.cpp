#include <iostream>
using namespace std;

int field[50][50];
int visit[50][50];

void dfs(int i, int j) {
	visit[i][j] = 1;
	//cout << i << " " << j << endl;
	
	if(i-1>=0 && field[i-1][j] == 1 && !visit[i-1][j])
		dfs(i-1, j);
	
	if(j-1>=0 && field[i][j-1] == 1 && !visit[i][j-1])
		dfs(i, j-1);
	
	if(i+1<50 && field[i+1][j] == 1 && !visit[i+1][j])
		dfs(i+1, j);
		
	if(j+1<50 && field[i][j+1] == 1 && !visit[i][j+1])
		dfs(i, j+1);
	
}

int main() {
	int T;
	cin >> T;
	for(int n=0; n<T; n++) {
		int col, row, K;
		cin >> col >> row >> K;
		for(int i=0; i<K; i++) {
			int x, y;
			cin >> x >> y;
			field[y][x] = 1;
		}
		
		int answer = 0;
		for(int i=0; i<row; i++) {
			for(int j=0; j<col; j++) {
				if(field[i][j] == 1 && !visit[i][j]) {
					dfs(i, j);
					answer += 1;
				}
			}
		}
		cout << answer << endl;
		
		for(int a=0; a<50; a++) {
			for(int b=0; b<50; b++) {
				visit[a][b] = 0;
				field[a][b] = 0;
			}
		}
	}
}
