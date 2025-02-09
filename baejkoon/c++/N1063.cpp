#include <iostream>
#include <string>

using namespace std;

int main() {
	string k, s;
	int n;
	cin >> k >> s >> n;
	pair<int, int> kp = {k[0]-'A'+1, k[1]-'0'};
	pair<int, int> sp = {s[0]-'A'+1, s[1]-'0'};
	
	for(int i=0; i<n; i++) {
		string tmp;
		cin >> tmp;
		int dx = 0;
		int dy = 0;
		if(!tmp.compare("R")) {
			dx++;
		}
		else if(!tmp.compare("L")) {
			dx--;
		}
		else if(!tmp.compare("B")) {
			dy--;
		}
		else if(!tmp.compare("T")) {
			dy++;
		}
		else if(!tmp.compare("RT")) {
			dx++;
			dy++;
		}
		else if(!tmp.compare("LT")) {
			dx--;
			dy++;
		}
		else if(!tmp.compare("RB")) {
			dx++;
			dy--;
		}
		else {
			dx--;
			dy--;
		}
		if(kp.first+dx >= 1 && kp.first+dx <= 8 && kp.second+dy >= 1 && kp.second+dy <= 8) {
			kp.first = kp.first+dx;
			kp.second = kp.second+dy;
		}
		if(kp.first == sp.first && kp.second == sp.second) {
			if(sp.first+dx >= 1 && sp.first+dx <= 8 && sp.second+dy >= 1 && sp.second+dy <= 8) {
				sp.first = sp.first+dx;
				sp.second = sp.second+dy;
			}
			else {
				kp.first = kp.first-dx;
				kp.second = kp.second-dy;
			}
		}
	}
	char a = kp.first + 'A' - 1;
	char b = sp.first + 'A' - 1;
	cout << a << kp.second << "\n" << b << sp.second;
	
	return 0;
}
