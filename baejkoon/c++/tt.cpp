#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> te;
	for(int i=0; i<20; i++)
		te.push_back(i);
	cout << te[1];
}
