#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	int answer = 0; 
	while(n != 0) {
		int tf = 0;
		
		string s = to_string(n);
		int idx = 0;
		while(idx < s.size()) {
			if(s[idx] == '1') {
				s = s.substr(0, idx) + s.substr(idx+1, s.size()-idx+1);
				tf = 1;
				answer++;
			}
			else
				idx++;
		}
		if(s.empty())
			n = 0;
		else
			n = stoi(s);
		
		if(!tf) {
			n--;
			answer++;
		}
	}
	cout << answer;
	
	return 0;
}
