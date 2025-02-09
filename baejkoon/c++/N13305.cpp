#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	long long int prices[n], distance[n-1];
	for(int i=0; i<n-1; i++)
		cin >> distance[i];
	for(int i=0; i<n; i++)
		cin >> prices[i];
		
	long long int p = prices[0];
	long long int answer = distance[0]*p;
	for(int i=1; i<n-1; i++) {
		if(p > prices[i])
			p = prices[i];
		answer = answer + p * distance[i];
	}
	
	cout << answer;
	
	return 0;
}
