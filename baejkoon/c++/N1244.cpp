#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool arr[n+1];
    for(int i=1; i<=n; i++)
        cin >> arr[i];
    int m;
    cin >> m;
    for(int i=0; i<m; i++) {
        int f, s;
        cin >> f >> s;
        if(f == 1) {
            int tmp = s;
            while(s <= n) {
                arr[s] = !arr[s];
                s += tmp;
            }
        }
        else {
            arr[s] = !arr[s];
            int l = s-1;
            int h = s+1;
            while(l>=1 && h <= n) {
                if(arr[l] == arr[h]) {
                    arr[l--] = !arr[l];
                    arr[h++] = !arr[h];
                }
                else break;
            }
        }
    }
    for(int i=1; i<=n; i++) {
        cout << arr[i] << " ";
        if(i%20 == 0)
            cout << "\n";
    }
    return 0;
}