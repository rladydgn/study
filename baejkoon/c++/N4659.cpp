#include <iostream>
#include <string>

using namespace std;

bool mo(char c) {
    char cc[] = {'a', 'e', 'i', 'o', 'u'};
    for(int i=0; i<5; i++) {
        if(c == cc[i]) return true;
    }
    return false;
}

void print(string s, bool c) {
    if(c)
        cout << "<" << s << "> is acceptable.\n";
    else
        cout << "<" << s << "> is not acceptable.\n";
}

int main() {
    while(true) {
        string s;
        cin >> s;
        if(s == "end") break;
        bool check_mo = false;
        char before = s[0];
        check_mo = mo(before);

        bool check = mo(before);
        int cnt = 1;

        bool check2 = false;

        for(int i=1; i<s.size(); i++) {
            // 모음 하나를 반드시 포함하는지 체크
            if(!check_mo) check_mo = mo(s[i]);

            // 모음이 3개 혹은 자음이 3개 연속 오는지 체크
            if(check == mo(s[i])) cnt++;
            else {
                cnt = 1;
                check = !check;
            }
            if(cnt>=3) {
                print(s, false);
                check2 = true;
                break;
            }

            // 같은 글자가 연속으로 두번 오는 경우 체크
            if(before == s[i] && !(s[i] == 'o' || s[i]== 'e')) {
                print(s, false);
                check2 = true;
                break;
            }
            before = s[i];
        }
        if(!check_mo && !check2) {
            print(s, false);
        }
        else if(!check2) {
            print(s, true);
        }
    }

    return 0;
}