#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if(a<b && a<c) {
        cout << a << " " << min(b, c) << " " << max(b, c);
    }
    else if(b<a && b<c) {
        cout << b << " " << min(a, c) << " " << max(a, c);
    }
    else {
        cout << c << " " << min(a, b) << " " << max(a, b);
    }
    return 0;
}