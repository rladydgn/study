#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int answer = 0;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        answer = answer + b%a;
    }
    cout << answer;
    return 0;
}