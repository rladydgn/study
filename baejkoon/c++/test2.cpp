#include <iostream>
using namespace std;


int main() {
	int A = 1000;


	int R = A / 10 + (A % 10) * 1000;
	int L = (A % 1000) * 10 + A/1000;
	cout << R << endl << L;
}

