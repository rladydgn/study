#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m;

void Dfs(int *arr, int idx, int cnt, string s) {
	cnt++;
	s += to_string(arr[idx]) + " ";
	
	if(m == cnt) {
		cout << s << "\n";
		return;
	}
	
	for(int i=idx; i<n; i++) {
		Dfs(arr, i, cnt, s);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	int arr[n];
	
	for(int i=0; i<n; i++)
		cin >> arr[i];
		
	sort(arr, arr+n);
	
	for(int i=0; i<n; i++)
		Dfs(arr, i, 0, "");
}
