#include <iostream>
#include <string>

using namespace std;

string reverse(string s) {
    for(int i=0; i<s.size()/2; i++) {
        swap(s[i], s[s.size()-1-i]);
    }
    return s;
}

int main() {
    string s;
    cin >> s;
    string answer = s;
    for(int i=1; i<=s.size()-2; i++) {
        for(int j=1; j<=s.size()-1-i; j++) {
            string a = reverse(s.substr(0, i));
            string b = reverse(s.substr(i, j));
            string c = reverse(s.substr(i+j, s.size()-i-j));
            if(a+b+c < answer) {
                answer = a+b+c;
            }
        }
    }
    cout << answer;

    return 0;
}