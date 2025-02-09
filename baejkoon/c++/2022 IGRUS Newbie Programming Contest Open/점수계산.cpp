#include <iostream>
#include <string>

using namespace std;

int arr[1000];
int answer;

int point(int& a, int & b) {
	string s = to_string(a*b);
	int ret = 0;
	for(int i=0; i<s.size(); i++)
		ret = ret + (s[i] - '0');
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		arr[tmp]++;
	}
	
	for(int i=1; i<=999; i++) {
		if(arr[i] == 0) continue;
		for(int j=1; j<=999; j++) {
			if(arr[j] == 0) continue;
			if(i == j && arr[i] < 2) continue;
			answer = max(answer, point(i, j));
		}
	}
	cout << answer;
}
