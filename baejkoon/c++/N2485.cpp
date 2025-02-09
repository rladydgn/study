#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int tree[n];
	int tree_dis[n-1];
	for(int i=0; i<n; i++)
		cin >> tree[i];
		
	for(int i=1; i<n; i++)
		tree_dis[i-1] = tree[i]-tree[i-1];
	
	int m = 999999999;
	for(int i=1; i<n-1; i++) {
		int a = tree_dis[i-1];
		int b = tree_dis[i];
		while(a%b != 0) {
			int c = a%b;
			a = b;
			b = c;
		}
		if(m > b)
			m = b;
		
		if(m == 1)
			break;
	}
	
	int answer = 0;
	for(int i=0; i<n-1; i++) {
		answer = answer + (tree_dis[i]/m)-1;
	}
	cout << answer;
}
