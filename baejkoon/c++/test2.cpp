#include <iostream>
using namespace std;


int main() {
	int a[4] = {1, 2, 3, 4};
	int b[4];
	
	b = a;
	
	b[1] = 100;
	
	cout << a[1];
}

