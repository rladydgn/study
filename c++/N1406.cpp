#include <iostream>
#include <string>
using namespace std;

int main() {
    // ����� ������
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string text;
    cin >> text;
    int n;
    cin >> n;

    int cur = text.size();
    string com;
    for(int i=0; i<n; i++) {
        cin >> com;
        if(com == "L") {
            if(cur != 0)
                cur--;
        }
        else if(com == "D") {
            if(cur != text.size())
                cur++;
        }
        else if(com == "B") {
                if(cur != 0) {
                    // Ŀ�� ������ string
                    string tRight = text.substr(cur);
                    // Ŀ�� ����(������ text ����)
                    string tLeft = text.substr(0, cur-1);
                    text = tLeft + tRight;
                }
        }
        else if(com == "P") {
            string tmp;
            cin >> tmp;
            string tRight = text.substr(cur);
            string tLeft = text.substr(0, cur);
            text = tLeft + tmp + tRight;
        }
    }
    cout << text;
}
