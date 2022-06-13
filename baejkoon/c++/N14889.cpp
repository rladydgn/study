#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int points[20][20];
int n;
int visit[20];
int mini = 99999999;

void dfs(int cnt, int idx) {
	
	// »ç¶÷ Àý¹Ý °ñ¶úÀ» °æ¿ì 
	if(cnt == n/2) {
		int suma = 0, sumb = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(visit[i] && visit[j])
					suma += points[i][j];
				else if(!visit[i] && !visit[j])
					sumb += points[i][j];
			}
		}
		// cout << suma << " " << sumb << endl;
		int tmp = abs(suma-sumb);
		if(mini > tmp)
			mini = tmp;
	}
	for(int i=idx; i<n; i++) {
		if(!visit[i]) {
			visit[i] = 1;
			dfs(cnt+1, i);
			visit[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> points[i][j];
		}
	}
	
	dfs(0, 0);
	cout << mini;
}
