#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[n+1][10];
	
	for(int i=0; i<10; i++)
		arr[1][i] = 1;
	
	for(int i=1; i<=n; i++)
		arr[i][0] = 1;
		
	for(int i=2; i<=n; i++) {
		for(int j=1; j<10; j++) {
			arr[i][j] = (arr[i-1][j] + arr[i][j-1]) % 10007;
		}
	}
	
	int answer = 0;
	for(int i=0; i<10; i++)
		answer += arr[n][i];
		
	cout << answer % 10007;
	
	return 0;
}
