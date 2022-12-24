#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(string str, char Delimiter) {
    istringstream iss(str);
    string buffer;
 
    vector<string> result;
 
    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);
    }
 
    return result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	
	unordered_set<string> m;
	
	for(int i=0; i<n; i++) {
		string tmp;
		cin >> tmp;
		m.insert(tmp);
	}
	
	for(int i=0; i<k; i++) {
		string tmp;
		cin >> tmp;
		
		vector<string> strs = split(tmp, ',');
		
		for(auto s: strs) {
			m.erase(s);
		}
		
		cout << m.size() << "\n";
	}
	return 0;
}
