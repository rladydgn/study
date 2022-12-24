#include <iostream>
#include <string>

using namespace std;

int arr[26];

int main() {
    string s;
    cin >> s;

    for(int i=0; i<s.size(); i++) {
        arr[s[i]-'A']++;
    }

    string answer = s;
    int start = 0;
    int end = s.size()-1;
    // ��� �� �־��� �ȳ־��� üũ
    bool check = false;
    for(int i=0; i<26; i++) {
        while(arr[i] != 0) {
            // ���ĺ� ������ Ȧ���� �ε� ���ڿ� ũ�Ⱑ ¦������ ���
            if(arr[i]%2 == 1 && s.size()%2 == 0) {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
            // ���ڿ��� ũ�Ⱑ Ȧ���ΰ��
            if(arr[i] == 1 && s.size()%2 == 1) {
                // Ȧ���� ���ĺ��� 1�� ���� ���� ���
                if(check) {
                    cout << "I'm Sorry Hansoo";
                    return 0;
                }
                else {
                    check = true;
                    arr[i] = 0;
                    answer[s.size()/2] = 'A' + i;
                }
            }
            else {
                answer[start++] = 'A' + i;
                answer[end--] = 'A' + i;
                arr[i] -= 2;
            }
        }
    }
    cout << answer;

    return 0;
}