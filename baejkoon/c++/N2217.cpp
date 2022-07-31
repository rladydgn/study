#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	int ropes[n];
	for(int i=0; i<n; i++) {
		cin >> ropes[i];
	}
	
	sort(ropes, ropes+n);
	long long int max = 0;
	for(int i=0; i<n; i++) {
		if(max < ropes[i]*(n-i))
			max = ropes[i]*(n-i);
	}
	cout << max;
}
