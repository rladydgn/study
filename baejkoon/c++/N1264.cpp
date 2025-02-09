#include <iostream>
#include <string>

using namespace std;

char arr[] = {'a', 'A', 'e', 'E', 'o', 'O', 'u', 'U', 'i', 'I'};

int main() {
    while(true) {
        string s;
        getline(cin, s);
        if(s == "#") break;
        int cnt = 0;
        for(int i=0; i<s.size(); i++) {
            for(int j=0; j<10; j++) {
                if(s[i] == arr[j]) cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}