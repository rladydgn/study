#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int answer = 0;
    while(n != 0) {
        answer = answer + n/5;
        n /= 5;
    }
    cout << answer;

    return 0;
}