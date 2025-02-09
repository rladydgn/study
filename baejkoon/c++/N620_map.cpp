#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	unordered_map<string, int> m1;
	unordered_map<int, string> m2;
	for(int i=1; i<=n; i++) {
		string tmp;
		cin >> tmp;
		m1[tmp] = i;
		m2[i] = tmp;
	}
	
	for(int i=0; i<m; i++) {
		string s;
		cin >> s;
		if(s[0] >= '0' && s[0] <= '9') {
			cout << m2[stoi(s)] << "\n";
		}
		else {
			cout << m1[s] << "\n";
		}
	}
}
