#include <iostream>

using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	
	int range[3] = {8, 4, 1};
	
	for(int i=0; i<3; i++) {
		if(n%range[i] == 0 && n/range[i] <= t) {
			cout << 1 << "\n" << t-(n/range[i]) << " " << range[i];
			return 0;
		}
	}
	
	pair<int, int> range2[3] = {{8, 4}, {8, 1}, {4, 1}};
	
	for(int i=0; i<3; i++) {
		if((n%range2[i].first)%range2[i].second == 0 && n/range2[i].first + (n%range2[i].first)/range2[i].second <= t) {
			cout << 2 << "\n" << t-(n/range2[i].first + (n%range2[i].first)/range2[i].second) << " " << range2[i].first << "\n";
			cout << t-(n%range2[i].first)/range2[i].second << " " << range2[i].second;
			return 0;
		}
	}
	
	int f = n%8;
	int o = f%4;
	if(n/8+f/4+o <= t) {
		cout << 3 << "\n";
		cout << t-(n/8+f/4+o) << " " << 8 << "\n";
		cout << t-(f/4+o) << " " << 4 << "\n";
		cout << t-o << " " << 1 << "\n";
		return 0;
	}
	
	cout << -1;
	
}
