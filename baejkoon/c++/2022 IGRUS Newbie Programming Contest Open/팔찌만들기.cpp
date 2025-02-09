#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int bead[n];
	for(int i=0; i<n; i++)
		cin >> bead[i];
		
	sort(bead, bead+n);
	long long int answer = 0;
	for(int i=1; i<n; i++) {
		answer = answer + (bead[i] - bead[i-1]);
	}
	answer = answer + (bead[n-1] - bead[0]);
	
	cout << answer;
} 
