#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	double arr[26];
	
	for(int i=0; i<n; i++)
		cin >> arr[i];
	
	stack<double> st;
	for(int i=0; i<s.size(); i++) {
		if(s[i] >= 'A' && s[i] <= 'Z') {
			st.push(arr[s[i]-'A']);
		}
		else {
			double a = st.top();
			st.pop();
			double b = st.top();
			st.pop();
			if(s[i] == '*')
				st.push(a*b);
			else if(s[i] == '+')
				st.push(a+b);
			else if(s[i] == '-')
				st.push(b-a);
			else
				st.push(b/a);
		}
	}
	
	cout << fixed;
	cout.precision(2);
	cout << st.top();
}
