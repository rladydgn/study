#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[n+1];
	
	for(int i=0; i<n; i++)
		cin >> arr[i+1];
	
	for(int i=2; i<=n; i++) {
		for(int j=1; j<=i/2; j++) {
			arr[i] = max(arr[i], arr[i-j]+arr[j]);
		}  
	}
	cout << arr[n];
	
	return 0;
}
