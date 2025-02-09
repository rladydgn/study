#include <iostream>
using namespace std;

int check[50];

int main() {
	int n;
	int answer = 0;
	cin >> n;
	char tf[n][n];
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++)
			cin >> tf[i][j];
	}
	
	
	for(int i=0; i<n; i++) {
		int cnt = 0;
		for(int j=0; j<n; j++) {
			if(tf[i][j] == 'Y') {
				if(check[j] == 0) {
					check[j] = 1;
					cnt++;
				}
				for(int k=0; k<n; k++) {
					if(tf[j][k] == 'Y' && check[k] == 0 && i != k) {
						check[k] = 1;
						cnt++;
					}
				}
			}
		}
		if(answer < cnt)
			answer = cnt;
		
		for(int j=0; j<n; j++)
			check[j] = 0;
	}
	cout << answer;
}
