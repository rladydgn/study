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
    // 가운데 값 넣었나 안넣었나 체크
    bool check = false;
    for(int i=0; i<26; i++) {
        while(arr[i] != 0) {
            // 알파벳 개수가 홀수개 인데 문자열 크기가 짝수개인 경우
            if(arr[i]%2 == 1 && s.size()%2 == 0) {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
            // 문자열의 크기가 홀수인경우
            if(arr[i] == 1 && s.size()%2 == 1) {
                // 홀수개 알파벳이 1개 보다 많은 경우
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