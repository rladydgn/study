#include <iostream>

using namespace std;

int check[1000];

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];

    for(int i=0; i<n; i++)
        arr[i] = i+1;

    int idx = k-1;
    check[idx] = 1;

    if(n == 1) {
        cout << "<" << arr[idx] << ">";
    }
    else {
        cout << "<" << arr[idx] << ", ";
    }
    for(int i=1; i<n; i++) {
        int cnt = 0;
        while(cnt != k) {
            idx = (idx+1)%n;
            if(check[idx] == 0) {
                cnt++;
            }
        }

        check[idx] = 1;

        if(i == n-1) {
            cout << arr[idx] << ">";
        }
        else {
            cout << arr[idx] << ", ";
        }
    }

    return 0;
}