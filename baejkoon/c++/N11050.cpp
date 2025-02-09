#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a = n;
    int b = k;
    if(k == 0) {
        cout << 1;
        return 0;
    }
    for(int i=1; i<k; i++) {
        a = a * (n-i);
        b = b * (k-i);
    }
    cout << a/b;
    return 0;
}