#include <iostream>

using namespace std;

int main() {
    int answer = 0;
    int number = 0;
    for(int i=0; i<5; i++) {
        int s = 0;
        for(int j=0; j<4; j++) {
            int t;
            cin >> t;
            s += t;
        }
        if (answer<s) {
            answer = s;
            number = i+1;
        }
    }
    cout << number << " " << answer;
    return 0;
}