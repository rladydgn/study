#include <iostream>
#include <deque>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

deque<char> t[4];
int visit[4];

void circle(int t_n, int direction) {
	if(direction == 1) {
		int tmp = t[t_n-1].back();
		t[t_n-1].pop_back();
		t[t_n-1].push_front(tmp);
	}
	
	else {
		int tmp = t[t_n-1].front();
		t[t_n-1].pop_front();
		t[t_n-1].push_back(tmp);
	}
}

int main() {
	for(int i=0; i<4; i++) {
		string s;
		cin >> s;
		for(int j=0; j<s.size(); j++)
			t[i].push_back(s[j]);
	}
	
	int n;
	cin >> n;
	
//	for(int i=0; i<8; i++) {
//		cout << t[0][i] << " "; 
//	}
//	cout << "test" << endl;
	
	for(int i=0; i<n; i++) {
		queue<pair<int, int> > q;
		int a, b;
		cin >> a >> b;
		
		q.push({a, b});
		
		while(!q.empty()) {
			int c, d;
			c = q.front().first;
			d = q.front().second;
			q.pop();
			
			if(visit[c-1] == 1)
				continue;
			
			visit[c-1] = 1;
			
			if( (c == 1 || c == 2 || c == 3) && t[c-1][2] != t[c][6]) {
				q.push({c+1, -d});
			}
			
			if( (c == 2 || c == 3 || c == 4) && t[c-1][6] != t[c-2][2]) {
				q.push({c-1, -d});
			}
			
			circle(c, d);
			
//			cout << "t n " << c << endl;
//			for(int i=0; i<8; i++) {
//				cout << t[c-1][i] << " "; 
//			}
//			cout << endl;
		}
		
		for(int j=0; j<4; j++)
			visit[j] = 0;
		
	}
	
	int answer = 0;
	for(int i=0; i<4; i++) {
		if(t[i][0] == '1')
			answer += pow(2, i);
	}
	
	cout << answer;
	return 0;
}
