#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int answer = 0;
	int points[n];
	for(int i=0; i<n; i++) {
		cin >> points[i];
	}
	
	int k = points[n-1];
	for(int i=n-2; i>=0; i--) {
		if(points[i] >= k) {
			answer += points[i]-k+1;
			k = points[i] - (points[i]-k+1);
		}
		else {
			k = points[i];
		}
	} 
	
	cout << answer;
}
