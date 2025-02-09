#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	
	int c = a, d = b;
	
	while(c%d != 0) {
		int k = c%d;
		c = d;
		d = k;
	}
	
	cout << d << "\n" << d*(a/d)*(b/d);
	return 0;
}
