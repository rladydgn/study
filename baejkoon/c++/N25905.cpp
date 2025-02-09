#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	if(n == 1 || n == 2) {
		cout << 1;
		return 0;
	}
	long long int a = 1;
	long long int b = 1;
	long long int c = 1;
	
	for(int i=3; i<=n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	cout << c;
}
