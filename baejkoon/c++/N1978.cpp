#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	int answer = 0;
	for(int i=0; i<n; i++) {
		int a;
		cin >> a;
		bool tf = true;
		if(a == 1) continue;
		for(int j=2; j<=sqrt(a); j++) {
			if(a%j == 0) {
				tf = false;
				break;
			}
		}
		if(tf)
			answer++;
	}
	cout << answer;
}
