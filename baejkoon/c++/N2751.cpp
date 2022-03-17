#include <iostream>
using namespace std;

// insertion

int main() {
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];
	
	// #include <algorithm>
	// sort(arr, arr+n)
	for(int i=1; i<n; i++) {
		for(int j=0; j<i; j++) {
			if(arr[i] < arr[j]) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	
	for(int i=0; i<n; i++)
		cout << arr[i] << "\n";
	return 0;
} 
