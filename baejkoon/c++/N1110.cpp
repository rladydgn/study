#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int k = n;
    int cnt = 0;
    while(true) {
        int t = k/10 + k%10;
        k = (k%10)*10 + t%10;
        cnt++;
        if(k==n) break;
    }
    cout << cnt;
    return 0;
}