#include <iostream>
#include <string>

using namespace std;

string str[50];
int check[50];

int main() {
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> str[i];
	}
	
	int answer = 0;
	for(int i=0; i<n; i++) {
		int tf = 0;
		for(int j=0; j<n; j++) {
			if(i == j || str[i].size() > str[j].size())
				continue;
				
			if(!str[i].compare(str[j]) && check[j] == 0) {
				check[i] = 1;
				check[j] = 1;
				continue;
			}
			
			if(!str[i].compare(str[j].substr(0, str[i].size()))) {
				tf = 1;
				break;
			}
		}
		if(!tf)
			answer++;
	}
	cout << answer;
}
