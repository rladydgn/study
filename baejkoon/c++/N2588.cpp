#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int a;
    string b;
    int answer = 0;
    cin >> a >> b;
    for(int i=b.size()-1; i>=0; i--) {
        int t = b[i] - '0';
        cout << a*(b[i] - '0') << "\n";
        answer += a*(b[i] - '0')*pow(10, b.size()-1-i);
    }
    cout << answer;

    return 0;
}