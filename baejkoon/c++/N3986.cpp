#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    int answer = n;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;

        int a = 0;
        int b = 0;
        for(int j=0; j<s.size(); j++) {
            if(s[j] == 'A') a = (a + 1);
            if(s[j] == 'B') b = (b + 1);

            if((a == 2 && b == 1 && s[j-1] == 'B') || (a == 1 && b == 2 && s[j-1] == 'A')) {
                answer--;
                a = 0; b = 0;
                break;
            }

            a %= 2;
            b %= 2;
        }
        if(a == 1 || b == 1) answer--;
    }
    cout << answer;

    return 0;
}