#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	string s, t;
	
	cin >> s >> t;
		
	int start = 0;
	int end = t.size()-1;
	
	while(s.size()-1 != abs(start-end)) {
		// cout << abs(start-end) << endl;
		if(start < end) {
			if(t[end] == 'A') {
				end--;
			}
			else {
				int tmp = end-1;
				end = start;
				start = tmp;
			}
		}
		else {
			if(t[end] == 'A') {
				end++;
			}
			else {
				int tmp = end+1;
				end = start;
				start = tmp;
			}
		}
	}
	
	string answer = "";
	if(start < end) {
		for(int i=start; i<=end; i++) {
			answer += t[i];
		}
	}
	else {
		for(int i=start; i>=end; i--) {
			answer += t[i];
		}
	}
	
	// cout << answer << endl;
	if(s.compare(answer))
		cout << 0;
	else
		cout << 1;
		
	return 0;
}
