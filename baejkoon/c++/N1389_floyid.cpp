#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	int paths[n+1][n+1];
	
	// path initialize
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=n; j++) {
			paths[i][j] = 99999;
		}
	}
	
	// find paths
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		paths[a][b] = 1;
		paths[b][a] = 1;
	}

	// find shortest paths
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				paths[i][j] = min(paths[i][j], paths[i][k]+paths[k][j]);
			}
		}
	}
	
//	for(int i=1; i<=n; i++) {
//		for(int j=1; j<=n; j++) {
//			cout << paths[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	int target;
	int answer = 9999;
	for(int i=1; i<=n; i++) {
		int kevin = 0;
		for(int j=1; j<=n; j++) {
			if(i != j) {
				kevin += paths[i][j];
			}
		}
		if(kevin < answer) {
			target = i;
			answer = kevin;
		}
	}
	
	cout << target;
}
