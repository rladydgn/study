#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int c;
    cin >> c;
    int k;
    k = (b+c)/60;
    a += k;
    a %= 24;
    b = (b+c)%60;

    cout << a << " " << b;
    return 0;
}