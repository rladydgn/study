#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct compare {
	bool operator()(int a, int b) {
		if(abs(a) > abs(b))
			return true;
		else if(abs(a) < abs(b))
			return false;
		else {
			if(a > b)
				return true;
			return false;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, compare> pq;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		if(tmp == 0) {
			if(pq.empty()) {
				cout << 0 << "\n";
				continue;
			}
			cout << pq.top() << "\n";
			pq.pop();
		}
		else {
			pq.push(tmp);
		}
	}
}
