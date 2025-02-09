#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int visit[8];
int a[8];
int n, m;

void dfs(int idx, int count, string s) {
	count++;
	s += to_string(a[idx]) + " ";
	if(count == m) {
		cout << s << "\n";
		return;
	}
	
	visit[idx] = 1;
	for(int i=0; i<n; i++) {
		if(!visit[i])
			dfs(i, count, s);
	}
	visit[idx] = 0;
}

int main() {
	cin >> n >> m;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	for(int i=0; i<n; i++)
		cin >> a[i];
		
	sort(a, a+n);
	
	for(int i=0; i<n; i++)
		dfs(i, 0, "");
}
