#include <iostream>
#include <string>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	
	if(a.size() < b.size()) {
		string tmp = a;
		a = b;
		b = tmp;
	}
	
	int n = a.size();
	int m = b.size();
	
	while(n%m != 0) {
		int tmp = n%m;
		n = m;
		m = tmp;
	}
	
	string c, d;
	for(int i=0; i<b.size()/m; i++) {
		c += a;
	}
	for(int i=0; i<a.size()/m; i++) {
		d += b;
	}
	
	if(!c.compare(d))
		cout << 1;
	else
		cout << 0;
}
