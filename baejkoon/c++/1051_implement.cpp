#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	int answer = 1;
	int arr[n][m];
	
	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		for(int j=0; j<s.size(); j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	
	for(int i=0; i<n-1; i++) {
		for(int j=0; j<m-1; j++) {
			for(int k=j+1; k<m; k++) {
				if(arr[i][j] == arr[i][k]) {
					// cout << i << " " << j << "   " << i << " " << k << endl;
					int len = k - j;
					if(i+len < n && arr[i+len][j] == arr[i][j] && arr[i+len][k] == arr[i][j] && answer < (len+1)*(len+1)) {
						answer = (len+1)*(len+1);
					}
				}
			}
		}
	}
	
	cout << answer;
}
