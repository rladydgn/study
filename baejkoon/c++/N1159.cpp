#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<char, int> m;
    vector<char> answer;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        m[s[0]] += 1;
    }
    for(auto iter=m.begin(); iter!=m.end(); iter++) {
        if(iter->second >= 5) answer.push_back(iter->first);
    }
    sort(answer.begin(), answer.end());
    if(answer.size() == 0) cout << "PREDAJA";
    
    for(char c: answer) {
        cout << c;
    }
    return 0;
}