#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	int x[n], c[n];
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		x[i] = tmp;
		c[i] = tmp; 
	}
	
	// input sort 
	sort(c, c+n);
	
	// match smaller numbers
	map<int, int> m;
	int idx = 0;
	
	m[c[0]] = idx;
	
	for(int i=1; i<n; i++) {
		if(c[i-1] != c[i])
			m[c[i]] = ++idx;
	}
	
	for(int i=0; i<n; i++) {
		cout << m[x[i]] << " ";
	}
}
