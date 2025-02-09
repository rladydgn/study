#include <iostream>

using namespace std;

int arr[20];
int n, s;
int answer;

void Dfs(int cnt, int idx, int now, int value) {
	if(cnt == now) {
		if(s == value)
			answer++;
		return;
	}
	
	for(int i=idx; i<n; i++) {
		Dfs(cnt, i+1, now+1, value+arr[i]);
	}
}

int main() {
	cin >> n >> s;
	
	for(int i=0; i<n; i++)
		cin >> arr[i];
	
	for(int i=0; i<n; i++) {
		Dfs(i+1, 0, 0, 0);
	}
	cout << answer;
	
	return 0;
}
