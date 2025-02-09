#include <iostream>
using namespace std;

int n;
int visit[14][14];
int answer;

// tf가 0이면 visit 0으로 1이면 1로 
void check(int r, int c, int tf) {
	for(int i=0; i<n; i++)
		visit[r][i] += tf;
		
	int idx = 1;
	for(int i=r+1; i<n; i++) {
		visit[i][c] += tf;
		if(c+idx < n)
			visit[i][c+idx] += tf;
		if(c-idx >= 0)
			visit[i][c-idx] += tf;
		idx++;
	}
}

void Dfs(int k) {
	if(k+1 == n) {
		for(int i=0; i<n; i++) {
			if(visit[k][i] == 0)
				answer++;
		}
		return;
	}
		
	for(int i=0; i<n; i++) {
		 if(visit[k][i] == 0) {
		 	// cout << k << " " << i << endl;
		 	check(k, i, 1);
		 	Dfs(k+1);
		 	check(k, i, -1);
		 }
	}
}

int main() {
	cin >> n;
	
	Dfs(0);
	
	cout << answer;
}
