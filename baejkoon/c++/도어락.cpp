#include <iostream>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	for(int i=0; i<t; i++) {
		int n, m;
		cin >> n >> m;
		string key, pw;
		cin >> key >> pw;
		bool tf = true;
		for(int j=0; j<pw.size(); j++) {
			for(int k=0; k<key.size(); k++) {
				if(key[k] != pw[j+k]) {
					tf = false;
					break;
				}
				tf = true; 
			}
			if(tf) {
				cout << 1 << "\n";
				break;
			}
		}
		if(!tf)
			cout << 0 << "\n";
	}
	return 0;
}
