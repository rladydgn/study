#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	unordered_map<string, int> m;
	int K, L;
	cin >> K >> L;
	string num[L];
	for(int i=0; i<L; i++) {
		cin >> num[i];
		m[num[i]] += 1;
	}
	
	int count = 0;
	for(int i=0; i<L; i++) {
		if(m[num[i]] > 1)
			m[num[i]]--;
		else {
			cout << num[i] << "\n";
			count++;
		}
		if(count == K)
			break;
	}
}
