#include <iostream>
#include <string>

using namespace std;

int alpha[26];
int answer;

void Dfs(int size, int len, string s) {
	// cout << s << endl;
	if(size == len) {
		answer++;
		return;
	}
	
	for(int i=0; i<26; i++) {
		char c = 'a' + i;
		string tmp = "";
		tmp += c;
		if(alpha[i] > 0 && s[s.size()-1] != c) {
			alpha[i]--;
			Dfs(size+1, len, s+tmp);
			alpha[i]++;
		}
	}
	
}

int main() {
	string s;
	cin >> s;
	int len = s.size();
	for(int i=0; i<s.size(); i++)
		alpha[s[i]-'a']++;

	for(int i=0; i<26; i++) {
		char c = 'a' + i;
		string tmp = "";
		tmp += c;
		if(alpha[i] > 0) {
			alpha[i]--;
			Dfs(1, len, tmp);
			alpha[i]++;
		}
	}
	cout << answer;
}
