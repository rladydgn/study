#include <iostream>
#include <string>

using namespace std;

int strike[100], ball[100];
string numbers[100];

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        string s;
        int q, w;
        cin >> s >> q >> w;
        numbers[i] = s;
        strike[i] = q;
        ball[i] = w;
    }
    int answer = 0;
    for(int i=1; i<=9; i++) {
        char a = i + '0';
        for(int j=1; j<=9; j++) {
            char b = j + '0';
            if(a == b) continue;
            for(int k=1; k<=9; k++) {
                char c = k + '0';
                if(a == c || b == c) continue;
                bool check = true;
                for(int l=0; l<n; l++) {
                    int st = 0, ba = 0;
                    if(a == numbers[l][0]) st++;
                    if(b == numbers[l][1]) st++;
                    if(c == numbers[l][2]) st++;
                    if(a == numbers[l][1] || a == numbers[l][2]) ba++;
                    if(b == numbers[l][0] || b == numbers[l][2]) ba++;
                    if(c == numbers[l][0] || c == numbers[l][1]) ba++;
                    if(strike[l] != st || ball[l] != ba) {
                        check = false;
                        break;
                    }
                }
                if(check) answer++;
            }
        }
    }
    cout << answer;

    return 0;
}