#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for(int i=0; i<T; i++) {
		int N;
		cin >> N;
		deque<char> dq;
		char tmp;
		cin >> tmp;
		dq.push_back(tmp);
		for(int j=1; j<N; j++) {
			cin >> tmp;
			if(dq.front() >= tmp)
				dq.push_front(tmp);
			else
				dq.push_back(tmp);
		}
		
		for(deque<char>::iterator it=dq.begin(); it != dq.end(); it++)
			cout << *it;
		cout << "\n";
	}
}
