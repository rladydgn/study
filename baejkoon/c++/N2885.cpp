#include <iostream>

using namespace std;

int main() {
	int k;
	cin >> k;
	
	int ex = 2;
	
	while(ex < k) {
		ex *= 2;
	}
	
	int answer = ex;
	int cnt = 0;
	while(k != 0) {
		if(k >= ex) {
			k -= ex;
		}
		
		if(k == 0) break;
		cnt++;
		ex /= 2;
	}
	
	cout << answer << " " << cnt;
}
