#include <iostream>
#include <string>

using namespace std;

// ����� �ܾ� ���� ���
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
        // < �ϰ�� ������ ����� �ܾ� ���, > ���� ���
        if(s[i] == '<') {
            flush(c);
            while(s[i] != '>') {
                cout << s[i++];
            }
            cout << s[i];
            c = "";
        }
        // ' '�� ��� ������ ����� �ܾ� ������ ���, ' '���
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