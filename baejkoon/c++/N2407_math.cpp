#include <iostream>

using namespace std;

long long int mom[100];
long long int son[50];

string cal(string a, int b) {
	string rev = "";
	for(int i=a.size()-1; i>=0; i--)
		rev += a[i];
	
	// cout << a << " " << b << endl;
	string s = rev;
	for(int i=1; i<b; i++) {
		int u = 0;
		for(int j=0; j<rev.size(); j++) {
			int tmp = (rev[j]-'0') + u;
			if(j<s.size()) {
				tmp = tmp + (s[j]-'0');
			}
			
			u = 0;
			if(tmp >= 10) {
				u = tmp/10;
				tmp = tmp%10;
			}
			
			// cout << "rev" << rev << endl;
			rev[j] = tmp + '0';
		}
		if(u != 0)
			rev = rev + to_string(u);
	}
	
	// cout << "rev" << rev << endl;
	string answer = "";
	for(int i=rev.size()-1; i>=0; i--)
		answer += rev[i];
	
	return answer;
}
int main() {
	int n, m;
	cin >> n >> m;
	
	// ´õ ÀûÀº °ö¼ÀÀ» À§ÇØ 
//	if(n/2<m)
//		m = n-m;
	
	int idx = 0;
	for(int i=n; i>n-m; i--) {
		mom[idx] = i;
		son[idx++] = i - (n-m);
	}
	
	for(int i=0; i<idx; i++) {
		for(int j=0; j<idx; j++) {
			if(mom[j]%son[i] == 0) {
				mom[j] = mom[j]/son[i];
				son[i] = 1;
				break;
			}
			else if(son[i]%mom[j] == 0) {
				son[i] = son[i]/mom[j];
				mom[j] = 1;
			}
		}
	}
	
	string answer = "1";
	for(int i=0; i<idx; i++) {
		answer = cal(answer, mom[i]);
		// cout << answer << endl;
	}
	
	cout << answer;
}
