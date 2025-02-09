#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int cnt = 0;
    string answer = "";
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '.') {
            if(cnt == 2)
                answer += "BB.";
            else if(cnt == 0)
                answer += ".";
            else {
                cout << -1;
                return 0;
            }
            cnt = 0;
        }
        else if(s[i] == 'X')
            cnt++;
        
        if(cnt == 4) {
            cnt = 0;
            answer += "AAAA";
        }
    }
    if(cnt != 2 && cnt != 0) {
        cout << -1;
        return 0;
    }
    if(cnt == 2)
        answer += "BB";

    cout << answer;
    return 0;
}