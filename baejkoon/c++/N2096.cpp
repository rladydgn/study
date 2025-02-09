#include <iostream>
using namespace std;

int max_t(int const &a, int const &b, int const &c) {
	if(a>=b && a>=c)
		return a;
	if(b>=a && b>=c)
		return b;
	return c;
}

int min_t(int const &a, int const &b, int const &c) {
	if(a<=b && a<=c)
		return a;
	if(b<=a && b<=c)
		return b;
	return c;
}

int main() {
	int n;
	cin >> n;
	int dp_max[2][3], dp_min[2][3];
	
	for(int i=0; i<3; i++) {
		int tmp;
		cin >> tmp;
		dp_max[0][i] = tmp;
		dp_min[0][i] = tmp;
	}
	
	int a, b, c;
	for(int i=1; i<n; i++) {
		cin >> a >> b >> c;
		dp_max[1][0] = max(dp_max[0][0]+a, dp_max[0][1]+a);
		dp_min[1][0] = min(dp_min[0][0]+a, dp_min[0][1]+a);
		
		dp_max[1][1] = max_t(dp_max[0][0]+b, dp_max[0][1]+b, dp_max[0][2]+b);
		dp_min[1][1] = min_t(dp_min[0][0]+b, dp_min[0][1]+b, dp_min[0][2]+b);
		
		dp_max[1][2] = max(dp_max[0][1]+c, dp_max[0][2]+c);
		dp_min[1][2] = min(dp_min[0][1]+c, dp_min[0][2]+c);
		
		for(int j=0; j<3; j++) {
			dp_max[0][j] = dp_max[1][j];
			dp_min[0][j] = dp_min[1][j];
		}
	}
	
	int max_answer = max_t(dp_max[0][0], dp_max[0][1], dp_max[0][2]);
	int min_answer = min_t(dp_min[0][0], dp_min[0][1], dp_min[0][2]);
	
	cout << max_answer << " " << min_answer;
}
