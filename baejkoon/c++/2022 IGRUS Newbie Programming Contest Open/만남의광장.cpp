#include <iostream>

using namespace std;

int visited[100][100];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int arr[n][m];
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> arr[i][j];
		}
	}
	
	int xsum[m], ysum[n];
	
	for(int x=0; x<m; x++) {
		int sum = 0;
		for(int y=0; y<n; y++) {
			sum += arr[y][x];
		}
		xsum[x] = sum;
	}
	
	for(int y=0; y<n; y++) {
		int sum = 0;
		for(int x=0; x<m; x++) {
			sum += arr[y][x];
		}
		ysum[y] = sum;
	}
	
	int answer = -99999999;
	for(int i=0; i<n-1; i++) {
		for(int j=i+1; j<n; j++) {
			for(int k=0; k<m-1; k++) {
				for(int l=k+1; l<m; l++) {
					int sum = ysum[i] + ysum[j] + xsum[k] + xsum[l];
					sum = sum - arr[i][k] - arr[i][l] - arr[j][k] - arr[j][l];
					sum = sum + (j-i-1)*(l-k-1);
					if(answer < sum)
						answer = sum;
				}
			}
		}
	}
	cout << answer;
	
	return 0;
}
