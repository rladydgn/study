#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        int cnt = 0;
        bool tf = true;
        while(pow(2, cnt) < s.size()) {
            int start = pow(2, cnt) - 1;
            int gap = pow(2, cnt+1);
            char check = '0';
            for(int j=start; j<s.size(); j+=gap) {
                if(j == start) {
                    check = s[j];
                    continue;
                }

                if(check == s[j]) {
                    cout << "NO" << "\n";
                    tf = false;
                    break;
                }
                check = s[j];
            }
            cnt++;
            if(!tf) break;
        }
        if(tf)
            cout << "YES" << "\n";
    }
    return 0;
}