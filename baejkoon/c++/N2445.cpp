#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n*2; j++) {
            if(i+1>j || n*2-i-2<j)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }

    for(int i=1; i<n; i++) {
        for(int j=0; j<n*2; j++) {
            if(n-i>j || n+i-1<j)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
    return 0;
}