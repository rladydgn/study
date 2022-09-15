#include <iostream>
#include <cmath>

using namespace std;

long long int n, r, c;

void Dfs(int now_n, long long int now_v) {
	if(r == 0 && c == 0) {
		cout << now_v;
		return;
	}
	
	if(r == 0 && c == 1) {
		cout << now_v + 1;
		return;
	}
	
	if(r == 1 && c == 0) {
		cout << now_v + 2;
		return;
	}
	
	if(r == 1 && c == 1) {
		cout << now_v + 3;
		return;
	}
	
	if(r < pow(2, now_n-1) && c < pow(2, now_n-1))
		Dfs(now_n-1, now_v);
	else if(r >= pow(2, now_n-1) && c < pow(2, now_n-1)) {
		r = r - pow(2, now_n-1);
		Dfs(now_n-1, now_v+pow(2, now_n-1)*pow(2, now_n));
	}
	else if(r < pow(2, now_n-1) && c >= pow(2, now_n-1)) {
		c = c - pow(2, now_n-1);
		Dfs(now_n-1, now_v+pow(2, now_n-1)*pow(2, now_n-1));
	}
	else {
		r = r - pow(2, now_n-1);
		c = c - pow(2, now_n-1);
		Dfs(now_n-1, now_v+pow(2, now_n-1)*pow(2, now_n)+pow(2, now_n-1)*pow(2, now_n-1));
	}
}

int main() {
	cin >> n >> r >> c;
	
	Dfs(n, 0);
}
