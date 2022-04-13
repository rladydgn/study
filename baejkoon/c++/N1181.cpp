#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(arr[i].size() < arr[j].size()) {
                string tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    int idx[51] = {0, };
    int bef = 1;

    for(int i=0; i<n; i++) {
        int tmp = arr[i].size();
        if(bef != tmp) {
            idx[bef] = i;
            bef = tmp;
        }
    }
    idx[bef] = n;

    bef = 0;
    for(int i=0; i< 51; i++) {
        if(idx[i] != 0) {
            sort(arr+bef, arr+idx[i]);
            bef = idx[i];
        }
    }

    for(int i=0; i<n-1; i++) {
        if(arr[i] != arr[i+1])
            cout << arr[i] << "\n";
    }
    cout << arr[n-1];
}
