#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	int jump[n+1];
	int answer[n+1];
	for(int i=1; i<=n; i++) {
		cin >> jump[i];
	}
	
	answer[n] = 1;
	for(int i=n-1; i>0; i--) {
		if(jump[i] == 0) {
			answer[i] = answer[i+1] + 1;
		}
		else {
			if(jump[i]+i+1 <= n) {
				answer[i] = answer[jump[i]+i+1] + 1;
			}
			else
				answer[i] = 1;
		}
	}
	
	for(int i=1; i<=n; i++)
		cout << answer[i] << " ";
}
