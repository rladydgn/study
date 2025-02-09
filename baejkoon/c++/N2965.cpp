#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int cnt = 0;
    while(a+1 < b || b+1 < c) {
        if(b-a > c-b) {
            c = b;
            b -= 1;
        }
        else {
            a = b;
            b += 1;
        }
        cnt++;
    }
    cout << cnt;
    return 0;
}