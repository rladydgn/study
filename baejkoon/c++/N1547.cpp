#include <iostream>

using namespace std;

int main() {
    int n;
    int arr[] = {0, 1, 2, 3};
    cin >> n;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        int tmp;
        tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }
    for(int i=1; i<=3; i++)
        if(arr[i] == 1)
            cout << i;

    return 0;
}