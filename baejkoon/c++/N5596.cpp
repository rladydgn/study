#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    int m, n;
    cin >> a >> b >> c >> d;
    m = a+b+c+d;
    cin >> a >> b >> c >> d;
    n = a+b+c+d;
    cout << max(m, n);
    return 0;
}