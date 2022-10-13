#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, m;
	string a, b;
	cin >> n >> a >> m >> b;
	
	int t_p = a.size()-1;
	int cnt = 0;
	int check = 0;
	int b_p = 0;
	
	while(check <= a.size()) {
		cnt++;
		check++;
		t_p = (t_p+1)%a.size();
		if(a[t_p] == b[b_p]) {
			check = 0;
			b_p++;
		}
		
		if(b_p == b.size())
			break;
	}
	
	if(check <= a.size())
		cout << cnt;
	else
		cout << -1;
	
} 
