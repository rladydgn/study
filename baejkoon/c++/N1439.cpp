#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    char c = s[0];
    int cnt = 1;
    for(int i=1; i<s.size(); i++) {
        if(c != s[i]) {
            cnt++;
            c = s[i];
        }
    }
    cout << cnt/2;

    return 0;
}