#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    int answer = 0;
    for(int i=0; i<n; i++) {
        string tmp;
        cin >> tmp;
        bool tf = true;
        int s = tmp[0] - 'a';
        int alpha[26] = {0, };
        alpha[s] = 1;
        for(int j=1; j<tmp.size(); j++) {
            if(alpha[tmp[j]-'a'] == 0 || s == tmp[j]-'a'){
                alpha[tmp[j]-'a'] = 1;
            }
            else if(alpha[tmp[j]-'a'] = 1) {
                tf = false;
                break;
            }
            s = tmp[j] - 'a';
        }
        if(tf)
            answer += 1;
    }
    cout << answer;
    return 0;
}