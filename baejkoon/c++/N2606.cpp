#include <iostream>

using namespace std;

int route[100][100];
int visit[100];
int answer, computer;

void dfs(int n) {
	for(int i=0; i<computer; i++) {
		if(route[n][i] && !visit[i]) {
			visit[i] = 1;
			answer++;
			dfs(i);
		}
	}
}

int main() {
	int n;
	cin >> computer >> n;
	
	for(int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		route[x-1][y-1] = 1;
		route[y-1][x-1] = 1;
	}
	visit[0] = 1;
	dfs(0);
	cout << answer;
}
