#include <iostream>

using namespace std;

int main() {
    int row = 1, col = 1, value = 1;
    int n;
    cin >> n;
    for(int i=1; i<)
    while(true) {
        if(value == n) break;
        int a = col + (row-1) + value;
        int b = value + col + row;
        if(a <= n && b <= n) {
            cout << "tt" << endl;
            if(a>b) {
                value = a;
                col++;
            }
            else {
                value = b;
                row++;
            }
        }
        else if(a <= n) {
            value = a;
            col++;
        }
        else {
            value = b;
            row++;
        }
        cout << value << endl;
    }
    cout << row << "/" << col;

    return 0;
}