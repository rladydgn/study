#include <iostream>
#include <cmath>

using namespace std;

double x[200001], y[200001];
double lcum[200001], rcum[200001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	for(int i=1; i<=n; i++)
		cin >> x[i];
	for(int i=1; i<=n; i++)
		cin >> y[i];
	
	// 지수 표현 방지
	cout << fixed;
	 
	int stat = 0;
	for(int i=2; i<=n; i++) {
		if(y[i-1] < y[i]) stat = 3;
		else if(y[i-1] == y[i]) stat = 2;
		else stat = 1;
		
		lcum[i] = sqrt((x[i]-x[i-1])*(x[i]-x[i-1]) + (y[i]-y[i-1])*(y[i]-y[i-1])) * stat + lcum[i-1];
	}
	
	for(int i=n-1; i>=1; i--) {
		if(y[i+1] < y[i]) stat = 3;
		else if(y[i+1] == y[i]) stat = 2;
		else stat = 1;
		
		rcum[i] = sqrt((x[i]-x[i+1])*(x[i]-x[i+1]) + (y[i]-y[i+1])*(y[i]-y[i+1])) * stat + rcum[i+1];
	}
	
	double answer;
	for(int i=0; i<q; i++) {
		int a, b;
		cin >> a >> b;
		if(a < b)
			answer = lcum[b]-lcum[a];
		else
			answer = rcum[b]-rcum[a];
		cout << answer << "\n";
	}
	
	return 0;
} 
