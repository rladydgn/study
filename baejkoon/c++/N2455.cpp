#include <iostream>

using namespace std;

int main() {
    int answer = 0;
    int now = 0;
    while(true) {
        int a, b;
        cin >> a >> b;
        if(b==0) break;
        now -= a;
        now += b;
        answer = max(answer, now);
    }
    cout << answer;

    return 0;
}