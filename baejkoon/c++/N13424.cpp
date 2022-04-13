#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T, N, M;
	cin >> T;
	for(int i=0; i<T; i++) {
		cin >> N >> M;
		vector<vector<int> > answer;
		vector<vector<int> > route(N, vector<int>(N, 999999));
		// 비밀통로 
		for(int j=0; j<M; j++) {
			int a, b, c;
			cin >> a >> b >> c;
			route[a-1][b-1] = c;
			route[b-1][a-1] = c;
		}
		vector<int> sPath;
		int K;
		cin >> K;
		for(int j=0; j<K; j++) {
			int a;
			cin >> a;
			a -= 1;
			sPath = route[a];
			vector<int> check(N);
			check[a] = true;
			sPath[a] = 0;
			for(int k=1; k<N; k++) {
				int min = 1001;
				int idx = -1;
				for(int m=0; m<N; m++) {
					if(min > sPath[m] && !check[m]) {
						min = sPath[m];
						idx = m;
					}
				}
				if(idx == -1)
					break;
				check[idx] = true;
				
				for(int m=0; m<N; m++) {
					if(route[idx][m]+min <= sPath[m])
						sPath[m] = route[idx][m] + min;
				}
			}
			answer.push_back(sPath);
		}
		int min = 999999999;
		int room = 0;
		for(int a=0; a<answer[0].size(); a++) {
			int sum = 0;
			for(int b=0; b<answer.size(); b++) {
				sum += answer[b][a];
			}
			if(min > sum) {
				min = sum;
				room = a+1;
			}
		}
		cout << room << "\n";
//		for(int a=0; a<answer.size(); a++) {
//			for(int b=0; b<answer[a].size(); b++)
//				cout << answer[a][b] << " ";
//			cout << endl;
//		}
	}
}
