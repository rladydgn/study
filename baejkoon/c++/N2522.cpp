#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n*2-1; i++) {
        int k = i+1;
        if(k>n)
            k = n*2-k;
        for(int j=0; j<n-k; j++) {
            cout << " ";
        }
        for(int j=0; j<k; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}