#include <iostream>
#include <map>
using namespace std;

int main() {
	int k, n;
	cin >> k;
	int arr1[k];
	map <int, int> m1;
	for(int i=0; i<k; i++) {
		int tmp;
		cin >> tmp;
		m1[tmp] = 1;
	}
	cin >> n;
	int arr2[n];
	for(int i=0; i<n; i++)
		cin >> arr2[i];
	
	for(int i=0; i<n; i++) {
		if(m1[arr2[i]])
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}
	return 0;
}
