#include <iostream>
#include <queue>
using namespace std;

int paper[100][100];
int n, m;

void Bfs(int start_n, int start_m) {
	// check out boundary 0 -> 2 
	queue<pair<int ,int> > q;
	q.push({start_n, start_m});
	
	while(!q.empty()) {
		pair<int, int> c = q.front();
		q.pop();
		// cout << c.first << " " << c.second << endl;
		if(paper[c.first][c.second] == 0)
			paper[c.first][c.second] = 2;
		
		else
			continue;
			
		if(c.first-1 >= 0)
			q.push({c.first-1, c.second});
		if(c.first+1 < n)
			q.push({c.first+1, c.second});
		if(c.second-1 >= 0)
			q.push({c.first, c.second-1});
		if(c.second+1 < m)
			q.push({c.first, c.second+1});
	}
}

bool Check_cheese() {
	bool tf = false;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(paper[i][j] == 1) {
				int cnt = 0;
				if(paper[i-1][j] == 2)
					cnt++;
				if(paper[i+1][j] == 2)
					cnt++;
				if(paper[i][j-1] == 2)
					cnt++;
				if(paper[i][j+1] == 2)
					cnt++;
					
				if(cnt >= 2) {
					paper[i][j] = 3;
					tf = true;
					// cout << i << " " << j << endl;
				}
			}
		}
	}
	if(tf)
		return true;
	return false;
}

void Delete_cheese() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(paper[i][j] == 3) {
				paper[i][j] = 0;
				Bfs(i, j);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> paper[i][j];
		}
	}
	Bfs(0, 0);
	
	// check will delete cheese
	// if there is a cheese to remove, do while.
	int answer = 0;
	while(Check_cheese()) {
		Delete_cheese();
		answer++;
	}
	
	cout << answer;
}
