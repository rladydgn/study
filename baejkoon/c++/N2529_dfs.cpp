#include <iostream>
#include <cmath>
#include <string>

using namespace std;

long long int max_ = 0, min_ = 9999999999;
int n;
char arr[9];
int visit[10];

void Dfs(int cnt, string answer, int before) {
	if(cnt == n) {
		if(stoll(answer) > max_)
			max_ = stoll(answer);
		if(stoll(answer) < min_)
			min_ = stoll(answer);
		return;
	}
	
	visit[before] = 1;
	
	for(int i=0; i<=9; i++) {
		if(visit[i]) continue;
		if(arr[cnt] == '<' && before < i) {
			Dfs(cnt+1, answer+to_string(i), i);
		}
		else if(arr[cnt] == '>' && before > i) {
			Dfs(cnt+1, answer+to_string(i), i);
		}
	}
	
	visit[before] = 0;
}

int main() {
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	
	for(int i=0; i<=9; i++)
		Dfs(0, to_string(i), i);
		
	if(to_string(max_).size() != n+1)
		cout << "0" << max_ << "\n";
	else
		cout << max_ << "\n";
	
	if(to_string(min_).size() != n+1)
		cout << "0" << min_;
	else
		cout << min_;
		
	return 0;
}
