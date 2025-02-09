#include <iostream>
#include <deque>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	deque<int> d;
	
	for(int i=0; i<n; i++)
		d.push_back(i+1);
		
	while(!d.empty()) {
		cout << d.front() << " ";
		d.pop_front();
		
		if(!d.empty()) {
			int tmp = d.front();
			d.pop_front();
			d.push_back(tmp);
		}
	}
}
