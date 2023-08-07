#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    double arr[n];

    double ma = 0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        ma = max(ma, arr[i]);
    }

    double sum = 0;
    for(int i=0; i<n; i++) {
        sum = sum + (arr[i]/ma*100);
    }

    cout << sum/n;
    return 0;
}