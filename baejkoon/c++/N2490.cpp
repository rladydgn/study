#include <iostream>

using namespace std;

int main() {
    for(int i=0; i<3; i++) {
        int a = 0;
        for(int j=0; j<4; j++) {
            int k;
            cin >> k;
            if(k==0) a += 1;
        }
        if(a==0)
            cout << "E" << "\n";
        else if(a==1)
            cout << "A" << "\n";
        else if(a==2)
            cout << "B" << "\n";
        else if(a==3)
            cout << "C" << "\n";
        else
            cout << "D" << "\n";
    }
    return 0;
}