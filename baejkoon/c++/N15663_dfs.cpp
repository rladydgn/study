#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
int arr[8];
int visit[8];
int answer[8];

void Dfs(int cnt) {
	if(cnt == m) {
		for(int i=0; i<m; i++)
			cout << answer[i] << " ";
		cout << '\n';
	}
	
	if(visit[0] == 0) {
		visit[0] = 1;
		answer[cnt] = arr[0];
		Dfs(cnt+1);
		visit[0] = 0;
	}
	
	for(int i=1; i<n; i++) {
		if(arr[i] == arr[i-1] && visit[i-1] == 0)
			continue;
		if(visit[i] == 0) {
			visit[i] = 1;
			answer[cnt] = arr[i];
			Dfs(cnt+1);
			visit[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr+n);
	
	Dfs(0);
	
	return 0;
}
