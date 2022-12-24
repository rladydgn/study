#include <iostream>

using namespace std;

long long int max_ = -999999999;
long long int min_ = 999999999;
// + - * /
int operators[4];
int arr[11];
int n;

void Dfs(int idx, int value) {
	if(idx == n) {
		if(value < min_)
			min_ = value;
		if(value > max_)
			max_ = value;
		return;
	}
	
	for(int i=0; i<4; i++) {
		if(operators[i] != 0) {
			operators[i] -= 1;
			if(i == 0) {
				Dfs(idx+1, value+arr[idx]);
			}
			else if(i == 1) {
				Dfs(idx+1, value-arr[idx]);
			}
			else if(i == 2) {
				Dfs(idx+1, value*arr[idx]);
			}
			else if(i == 3) {
				Dfs(idx+1, value/arr[idx]);
			}
			operators[i] += 1;
		}
	}
}

int main() {
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	for(int i=0; i<4; i++)
		cin >> operators[i];
		
	Dfs(1, arr[0]);
	cout << max_ << "\n" << min_;
	
	return 0;
}
