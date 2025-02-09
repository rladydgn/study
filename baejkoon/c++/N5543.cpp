#include <iostream>

using namespace std;

int main() {
    int burger = 99999;
    int drink = 99999;
    for(int i=0; i<5; i++) {
        int tmp;
        cin >> tmp;
        if(i<3) {
            burger = min(burger, tmp);
        }
        else {
            drink = min(drink, tmp);
        }
    }
    cout << burger + drink - 50;
    return 0;
}