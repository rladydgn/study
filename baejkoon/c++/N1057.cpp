#include <iostream>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    a--;
    b--;

    int cnt = 1;
    while(true) {
        if(a/2 == b/2) {
            cout << cnt;
            break;
        }
        cnt++;
        a /= 2;
        b /= 2;
    }

    return 0;
}