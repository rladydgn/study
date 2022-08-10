#include <iostream>
#include <queue>
using namespace std;

int visit[51];
int party[50][51];
int party_check[50];

int main() {
	queue<int> q;
	int n, m, k;
	cin >> n >> m >> k;
	
	// who know the truth
	for(int i=0; i<k; i++) {
		int tmp;
		cin >> tmp;
		q.push(tmp);
	}
	
	for(int i=0; i<m; i++) {
		int tmp;
		cin >> tmp;
		for(int j=0; j<tmp; j++) {
			int tmp2;
			cin >> tmp2;
			party[i][tmp2] = 1;
		}
	}
	
	
	while(!q.empty()) {
		int a = q.front();
		q.pop();
		
		for(int i=0; i<m; i++) {
			if(party[i][a] == 1) {
				party_check[i] = 1;
				for(int j=0; j<51; j++) {
					if(party[i][j] == 1 && visit[j] == 0) {
						q.push(j);
						visit[j] = 1;
					}
				}
			}
		}
	}
	
	int answer = 0;
	for(int i=0; i<m; i++) {
		if(!party_check[i])
			answer++;
	}
	cout << answer;
}
