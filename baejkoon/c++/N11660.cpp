#include <iostream>
using namespace std;

int sums[1026][1026];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			int tmp;
			cin >> tmp;
			sums[i][j] = sums[i][j-1] + tmp;
		}
	}
	
	for(int i=0; i<m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int sum = 0;
		for(int k=x1; k<=x2; k++) {
			sum += sums[k][y2] - sums[k][y1-1];
		}
		cout << sum << "\n";
	}
}
