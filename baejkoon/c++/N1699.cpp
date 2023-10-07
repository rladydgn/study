#include <iostream>

using namespace std;

int arr[100001];

int main() {
    int n;
    cin >> n;
    for(int i=1; i<= n; i++) {
        int v = 1;
        arr[i] = 999999999;
        while(i - v*v >= 0) {
            arr[i] = min(arr[i], arr[i-v*v]);
            v += 1;
        }
        arr[i]++;
    }
    cout << arr[n];
    return 0;
}