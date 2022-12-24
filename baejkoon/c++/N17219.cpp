#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	unordered_map<string ,string> um;
	for(int i=0; i<n; i++) {
		string a, b;
		cin >> a >> b;
		um[a] = b;
	}
	
	for(int i=0; i<m; i++) {
		string a;
		cin >> a;
		cout << um[a] << "\n";
	}
	return 0;
}
