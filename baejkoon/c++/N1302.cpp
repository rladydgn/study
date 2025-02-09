#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    map<string, int> m;
    for(int i=0; i<n; i++) {
        string tmp;
        cin >> tmp;
        m[tmp] += 1;
    }

    string answer = "";
    int max_ = 0;
    for(auto iter=m.begin(); iter != m.end(); iter++) {
        if(max_ < iter->second) {
            answer = iter->first;
            max_ = iter->second;
        }
    }
    cout << answer;
    return 0;
}