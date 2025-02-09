#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int chicken_length[13][100];
int n, m;
int answer = 99999999;
vector<pair<int, int> > house, chicken;

void Dfs(int cnt, int idx, vector<int> c_house) {
	if(cnt == m) {
		int s = 0;
		for(int i=0; i<house.size(); i++) {
			int min_ = 9999999;
			for(int j=0; j<c_house.size(); j++) {
				if(chicken_length[c_house[j]][i] < min_) {
					min_ = chicken_length[c_house[j]][i];
				}
			}
			// cout << min_ << endl;
			s += min_;
		}
		// for(int j=0; j<c_house.size(); j++)
		// 	cout << chicken[c_house[j]].first << " " << chicken[c_house[j]].second << endl;
		// cout << s << endl << endl;
		if(s < answer)
			answer = s;
	}
	
	for(int i=idx; i<chicken.size(); i++) {
		vector<int> v;
		v = c_house;
		v.push_back(i);
		Dfs(cnt+1, i+1, v);
	}
}

int main() {
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			int tmp;
			cin >> tmp;
			if(tmp == 1)
				house.push_back({i, j});
			else if(tmp == 2)
				chicken.push_back({i, j});
		}
	}
	
	// every house, every chicken length.
	for(int i=0; i<chicken.size(); i++) {
		for(int j=0; j<house.size(); j++) {
			chicken_length[i][j] = abs(chicken[i].first-house[j].first) + abs(chicken[i].second-house[j].second);
		}
	}
	
	vector<int> v;
	Dfs(0, 0, v);
	
	cout << answer;
}
