#include <iostream>
using namespace std;

long long int bits[32];
long long int mod[32];

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	
	for(int i=0; i<32; i++) {
		if(b%2!=0)
			bits[i] = 1;
		b = b/2;
		if(b == 0)
			break;
	}
	mod[0] = a%c;
	for(int i=1; i<32; i++) {
		mod[i] = (mod[i-1]*mod[i-1])%c;
	}
	
	int answer = 1;
	for(int i=0; i<32; i++) {
		if(bits[i]) {
			answer = (answer*mod[i])%c;
		}
	}
	cout << answer;
	
}
