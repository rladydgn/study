#include <iostream>
#include <algorithm>

using namespace std;

int check[1000000];

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	
}

int main() {
	int N;
	cin >> N;
	
	pair<int, int> p[N];
	
	for(int i=0; i<N; i++) {
		int tmp;
		cin >> tmp;
		p[i] = {tmp, i};
	}
	
	sort(p, p + N);
	
	int answer = 1;
	for(int i=N-1; i>=0; i--) {
		cout << p[i].first << " " << p[i].second << " " << i << endl;
		if(p[i].second - answer + 1 < i)
			answer++;
	}
	
	cout << answer;
}
