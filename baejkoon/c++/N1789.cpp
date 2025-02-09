#include <iostream>

using namespace std;

int main() {
    long long int s;
    cin >> s;

    long long int i = 1;
    while(true) {
        long long int n = (i*(i+1))/2;
        if(n>s) {
            cout << i-1;
            return 0;
        }
        i++;
    }
    return 0;
}