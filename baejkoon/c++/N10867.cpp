#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool arr[2001] = {false, };
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        tmp += 1000;
        arr[tmp] = true;
    }

    for(int i=0; i<2001; i++) {
        if(arr[i])
            cout << i-1000 << " ";
    }
    return 0;
}
