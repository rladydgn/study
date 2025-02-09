#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    int answer = 0;
    if(a.size() < b.size()) {
        cout << answer;
        return 0;
    }
    for(int i=0; i<=a.size()-b.size(); i++) {
        bool tf = true;
        for(int j=0; j<b.size(); j++) {
            if(b[j] != a[j+i]) {
                tf = false;
                break;
            }
        }
        if(tf) {
            answer++;
            i += b.size() - 1;
        }
    }
    cout << answer;

    return 0;
}