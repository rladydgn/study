#include <iostream>

using namespace std;

void sorts(string& s, int i) {
	for(int k=i; k<s.size()-1; k++) {
		for(int l=k+1; l<s.size(); l++) {
			if(s[k] > s[l]) {
				char tmp = s[k];
				s[k] = s[l];
				s[l] = tmp;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		
		int tf = 0;
		for(int j=s.size()-2; j>=0; j--) {
			for(int k=s.size()-1; k>j; k--) {
				if(s[j] < s[k]) {
					char tmp = s[j];
					s[j] = s[k];
					s[k] = tmp;
					sorts(s, j+1);
					cout << s << "\n";
					tf = 1;
					break;
				}
			}
			if (tf)
				break;
		}
		if (!tf)
			cout << "BIGGEST" << "\n";
	}
}
