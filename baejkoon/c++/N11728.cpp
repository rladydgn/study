#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	
	int idx1 = 0, idx2 = 0;
	
	int arr1[n], arr2[m];
	
	for(int i=0; i<n; i++)
		cin >> arr1[i];
	for(int i=0; i<m; i++)
		cin >> arr2[i];
		
	while(idx1 < n && idx2 < m) {
		if(arr1[idx1] < arr2[idx2]) {
			cout << arr1[idx1++] << " ";
		}
		else if(arr1[idx1] > arr2[idx2]) {
			cout << arr2[idx2++] << " ";
		}
		else {
			cout << arr1[idx1++] << " " << arr2[idx2++] << " ";
		}
	}
	
	for(idx1; idx1<n; idx1++) {
		cout << arr1[idx1] << " ";
	}
	
	for(idx2; idx2<m; idx2++) {
		cout << arr2[idx2] << " ";
	}
	
	return 0;
}
