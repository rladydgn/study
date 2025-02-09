#include <iostream>
using namespace std;

int main() {
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int arr2[10000] = {0,};
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        arr2[tmp-1] += 1;
    }
    for(int i=0; i<10000; i++) {
        while(arr2[i] > 0) {
            arr2[i] -= 1;
            cout << i+1 << '\n';
        }
    }
    return 0;
}
