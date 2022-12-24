#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(char& a, char& b) {
	if(a<b)
		return false;
	return true;
}

int main() {
	string tmp;
	cin >> tmp;
	char arr[tmp.size()];
	for(int i=0; i<tmp.size(); i++)
		arr[i] = tmp[i];
	sort(arr, arr+tmp.size(), cmp);
	
	for(int i=0; i<tmp.size(); i++)
		cout << arr[i];
	return 0;
}
