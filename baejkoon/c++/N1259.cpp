#include <iostream>
#include <string>

using namespace std;

int main() {
    while(true) {
        string s;
        cin >> s;
        if(!s.compare("0"))
            return 0;
        bool tf = true;
        for(int i=0; i<s.size()/2; i++) {
            if(s[i] != s[s.size()-1-i]) {
                cout << "no" << "\n";
                tf = false;
                break;
            }
        }
        if(tf)
            cout << "yes" << "\n";
    }
}