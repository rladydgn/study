#include <iostream>
#include <cmath>

using namespace std;

int m, n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n;
		
	for(int i=m; i<=n; i++) {
		if(i == 1) continue;
		bool tf = true;
		for(int j=2; j<=sqrt(i); j++) {
			if(i%j == 0) {
				tf = false;
				break;
			}
		}
		if(tf)
			cout << i << "\n";
	}
}
