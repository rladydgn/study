#include <iostream>

using namespace std;

int main() {
    while(true) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0)
            return 0;
        
        if(a>b && a>c) {
            if(a*a == b*b+c*c) {
                cout << "right" << "\n";
            }
            else {
                cout << "wrong" << "\n";
            }
        }
        else if(b>c && b>a) {
            if(b*b == a*a+c*c) {
                cout << "right" << "\n";
            }
            else {
                cout << "wrong" << "\n";
            }
        }
        else {
            if(c*c == a*a+b*b) {
                cout << "right" << "\n";
            }
            else {
                cout << "wrong" << "\n";
            }
        }
    }
}