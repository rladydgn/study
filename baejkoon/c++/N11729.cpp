#include <iostream>
#include <string>

using namespace std;

string s = "";
int cnt;

void hanoi(int n, int a, int b, int c) {
    cnt++;
    if(n == 1) {
        s += to_string(a) + " " + to_string(c) + "\n";
        return;
    }
    hanoi(n-1, a, c, b);
    s += to_string(a) + " " + to_string(c) + "\n";
    hanoi(n-1, b, a, c);

}

int main() {
    int n;
    cin >> n;
    hanoi(n, 1, 2, 3);
    cout << cnt << "\n" << s;
    return 0;
}