#include <iostream>

using namespace std;

int arr[101][101];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i != j)
				arr[i][j] = 999999999;
		}
	}
	for(int i=0; i<m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if(arr[a][b] == 0 || (arr[a][b] != 0 && arr[a][b] > c))
			arr[a][b] = c;
	}
	
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j]);
			}
		}
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(arr[i][j] == 999999999) {
				cout << 0 << " ";
			}
			else {
				cout << arr[i][j] << " ";
			}
		}
		cout << "\n";
	}
}
