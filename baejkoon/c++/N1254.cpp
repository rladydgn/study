#include <iostream>
#include <string>

using namespace std;

// 펠린드롬인지 확인
bool check(string s) {
    int start = 0;
    int end = s.size()-1;

    while(start<end) {
        if(s[start] != s[end]) return false;
        start++;
        end--;
    }

    return true;
}

int main() {
    string s;
    cin >> s;
    int start = 0;
    int end = s.size()-1;

    int answer = s.size();
    for(int i=0; i<s.size(); i++) {
        if(check(s.substr(i))) break;
        answer++;
    }

    cout << answer;
    return 0;
}