#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr1, arr2;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		arr1.push_back(tmp);
	}
	sort(arr1.begin(), arr1.end());
	cin >> n;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		arr2.push_back(tmp);
	}
	
	for(int i=0; i<n; i++) {
		int min = 0;
		int max = arr1.size()-1;
		while(true) {
			int idx = (min+max)/2;
			//cout << "idx :" << idx << " min :" << min << " max :" << max << endl;
			if(arr2[i] == arr1[idx]) {
				cout << 1 << "\n";
				break;
			}
			else if(arr2[i] > arr1[idx])
				min = idx+1;
			else
				max = idx-1;
				
			if(min>max) {
				cout << 0 << "\n";
				break;
			}
		}
	}
	return 0;
}
