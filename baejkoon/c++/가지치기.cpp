#include <iostream>
#include <vector>

using namespace std;

int answer;
int n;
vector<int> v[50];

void find(int node) {
	if(v[node].size() == 0) {
		answer++;
		return;
	}
	for(int i=0; i<v[node].size(); i++) {
		find(v[node][i]);
	}
}

int main() {
	int t;
	cin >> t;
	for(int i=0; i<t; i++) {
		int del;
		cin >> n >> del;
		
		answer = 0;
		int root = 0;
		for(int j=0; j<50; j++)
			v[j].clear();
		
		for(int j=0; j<n; j++) {
			int tmp;
			cin >> tmp;
			if(tmp == -1)
				root = j;
			else
				v[tmp].push_back(j);
		}
		
		v[del].clear();
		find(root);
		
		cout << answer -1 << "\n";
	}
	
	return 0;
}
