#include <iostream>
#include <string>

using namespace std;
int cnt[10];

int main() {
	string n;
	
	cin >> n;
	
	for(int i=0; i<n.size(); i++) {
		if(n[i] == '9')
			n[i] ='6';
			
		cnt[n[i]-'0']++;
	}
	
	int answer = 0;
	
	if(cnt[6]%2==0)
		cnt[6] /= 2;
	else
		cnt[6] = cnt[6] / 2 + 1;
	
	for(int i=0; i<10; i++) {
		if(answer < cnt[i])
			answer = cnt[i];
	}
	
	cout << answer;
}
