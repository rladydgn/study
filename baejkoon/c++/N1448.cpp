#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];
		
	sort(arr, arr+n);
	
	for(int i=n-1; i>=2; i--) {
		if(arr[i] < arr[i-1]+arr[i-2]) {
			cout << arr[i] + arr[i-1] + arr[i-2];
			return 0;
		}
	}
	cout << -1;
	return 0;
}
