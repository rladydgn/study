#include <iostream>
#include <cmath>

using namespace std;

int arr[50001];

int main() {
    int n;
    cin >> n;

    int tmp = sqrt(n);
    for(int i=1; i<=tmp; i++) {
        arr[i*i] = 1;
    }

    for(int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}