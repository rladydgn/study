#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	string s;
	cin >> n >> m >> s;
	int arr[s.size()];
	if(s[0] == 'I')
		arr[0] = 1;
	else
		arr[0] = 0;
	
	for(int i=1; i<s.size(); i++) {
		if(s[i] == 'I' && s[i-1] == 'O') {
			arr[i] = arr[i-1] + 1;
		}
		else if(s[i] == 'I') {
			arr[i] = 1;
		}
		else if(s[i] == 'O' && s[i-1] == 'I') {
			arr[i] = arr[i-1] + 1;
		}
		else {
			arr[i] = 0;
		}
	}
	
	int check = 3 + 2*(n-1);
	int answer = 0;
	for(int i=0; i<s.size(); i++) {
		if(check <= arr[i] && s[i] == 'I')
			answer++;
	}
	cout << answer;
	return 0;
}
