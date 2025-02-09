#include <iostream>
#include <queue>

using namespace std;

int visit[100001];

int main() {
	int N, K;
	
	cin >> N >> K;
	
	queue<pair<int, int> > q;
	
	int answer;
	
	q.push({N, 0});
	
	while(!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		
		if(visit[a])
			continue;
		
		visit[a] = 1;
		
		if(a == K) {
			cout << b;
			return 0;
		}
		
		if(a-1 >= 0)
			q.push({a-1, b+1});
			
		if(a+1 <= 100000)
			q.push({a+1, b+1});
			
		if(a*2 <= 100000)
			q.push({a*2, b+1});
	}
}
