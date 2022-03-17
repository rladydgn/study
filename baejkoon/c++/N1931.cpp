#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if(a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int> > meet;
	for(int i=0; i<n; i++) {
		int a, b;
		cin >> a >> b;
		meet.push_back({a, b});
	}
	sort(meet.begin(), meet.end(), compare);
	
	int end = meet[0].second;
	int answer = 1;
	for(int i=1; i<n; i++) {
		if(meet[i].first >= end) {
			answer++;
			end = meet[i].second;
		}
	}
	cout << answer;
}
