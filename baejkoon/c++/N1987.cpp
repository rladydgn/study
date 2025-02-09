#include <iostream>
using namespace std;

int alpha[26];
char m[20][20];
int c[20][20];
int answer;
int R, C;

void dfs(int i, int j, int count) {
	count++;
	if(count > answer)
		answer = count;
	alpha[m[i][j]-65] = 1;
	c[i][j] = 1;
	
	if(i+1 < R && c[i+1][j] == 0 && alpha[m[i+1][j]-65] == 0)
		dfs(i+1, j, count);
	if(j+1 < C && c[i][j+1] == 0 && alpha[m[i][j+1]-65] == 0)
		dfs(i, j+1, count);
	if(i-1 >= 0 && c[i-1][j] == 0 && alpha[m[i-1][j]-65] == 0)
		dfs(i-1, j, count);
	if(j-1 >= 0 && c[i][j-1] == 0 && alpha[m[i][j-1]-65] == 0)
		dfs(i, j-1, count);
		
	alpha[m[i][j]-65] = 0;
	c[i][j] = 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	for(int i=0; i<R; i++) {
			cin >> m[i];
	}
	dfs(0, 0, 0);
	
	cout << answer;
}
