#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    string answer = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    for(int i=1; i<s.size()-1; i++) {
        for(int j=i+1; j<s.size(); j++) {
            string a = s.substr(0, i);
            string b = s.substr(i, j-i);
            string c = s.substr(j);
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            reverse(c.begin(), c.end());
            if(a+b+c < answer) {
                answer = a+b+c;
            }
        }
    }
    cout << answer;
    return 0;
}