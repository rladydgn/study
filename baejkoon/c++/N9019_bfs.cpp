#include <iostream>
#include <queue>
#include <string>
using namespace std;

// do not visit again same number.
int visit[10000];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int now, target;
		cin >> now >> target;
		
		queue<pair<int, string> >q;
		
		q.push({now, ""});
		visit[now] = 1;
		
		while(!q.empty()) {
			pair<int, string> p, check_p[4];
			p = q.front();
			q.pop();
			
			if(p.first == target) {
				cout << p.second << "\n";
				break;
			}
			// cout << p.first << endl;
			
			// D
			int D = (p.first * 2) % 10000;
			if(visit[D] == 0) {
				visit[D] = 1;
				q.push({D, p.second + "D"});
			}
			
			// S
			int S = (p.first -1 < 0) ? 9999 : p.first-1;
			if(visit[S] == 0) {
				visit[S] = 1;
				q.push({S, p.second + "S"});
			}
			
			// L
			int L = (p.first % 1000) * 10 + p.first/1000;
			if(visit[L] == 0) {
				visit[L] = 1;
				q.push({L, p.second + "L"});
			}
			
			// R
			int R = p.first / 10 + (p.first % 10) * 1000;
			if(visit[R] == 0) {
				visit[R] = 1;
				q.push({R, p.second + "R"});
			}
			
			// if use for loop, time out error....
//			for(int k=0; k<4; k++) {
//				if(visit[check_p[k].first] == 0) {
//					visit[check_p[k].first] = 1;
//					q.push(check_p[k]);
//				}
//			}
		}
		for(int j=0; j<10000; j++)
			visit[j] = 0;
	}
}
