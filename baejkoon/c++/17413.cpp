#include <iostream>
#include <string>

using namespace std;

// 저장된 단어 몽땅 출력
void flush(string& s) {
    if(!s.empty()) {
        for(int j=s.size()-1; j>=0; j--)
            cout << s[j];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    getline(cin, s);
    string c = "";
    for(int i=0; i<s.size(); i++) {
        // < 일경우 이전에 저장된 단어 출력, > 까지 출력
        if(s[i] == '<') {
            flush(c);
            while(s[i] != '>') {
                cout << s[i++];
            }
            cout << s[i];
            c = "";
        }
        // ' '일 경우 이전에 저장된 단어 있으면 출력, ' '출력
        else if(s[i] == ' '){
            flush(c);
            cout << s[i];
            c = "";
        }
        else {
            c += s[i];
        }
    }
    flush(c);

    return 0;
}