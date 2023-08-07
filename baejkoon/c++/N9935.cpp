#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string a, b;
    cin >> a >> b;

    string s = "";
    int idx = 0;
    for(int i=0; i<a.size(); i++) {
        s += a[i];

        if(s.size() >= b.size() && s[s.size()-1] == b[b.size()-1]) {
            bool check = true;
            for(int j=0; j<b.size(); j++) {
                if(s[s.size()-b.size()+j] != b[j]) {
                    check = false;
                    break;
                }
            }
            if(check) {
                s.erase(s.end()-b.size(), s.end());
            }
        }
    }

    if(s.size() == 0) {
        cout << "FRULA";
    }
    else {
        cout << s;
    }
    return 0;
}