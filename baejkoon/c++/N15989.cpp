#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        int n;
        cin >> n;
        int arr[n+1] = {0, };
        for(int j=1; j<=n; j++) {
            if(j == 1) arr[j] = 1;
            if(j == 2) arr[j] = 2;
            if(j == 3) arr[j] = 3;
            arr[j] = arr[j-1] + arr[j-]
        }
    }
}