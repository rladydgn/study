#include <iostream>

using namespace std;

int main() {
    int answer = 0;
    int now = 0;
    for (size_t i = 0; i < 10; i++) {
        int a, b;
        cin >> a >> b;
        now = now - a + b;
        if(now>10000) now = 10000;
        if(now>answer) answer = now;
    }
    cout << answer;

    return 0;
}