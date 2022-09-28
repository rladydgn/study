#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

set<string> answer;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	
	map<string, int> q;
	
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		string tmp;
		cin >> tmp;
		q[tmp] = 1;
	}
	
	int numbers = 0;
	for(int i=0; i<m; i++) {
		string tmp;
		cin >> tmp;
		if(q[tmp] == 1) {
			numbers++;
			answer.insert(tmp);
		}
	}
	
	cout << numbers << "\n";
	
	for(auto iter=answer.begin(); iter != answer.end(); iter++)
		cout << *iter << "\n";
}
