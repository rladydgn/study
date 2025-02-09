#include <iostream>

using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    int rank = 1;
    int cnt = 0;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        if(m>a) {
            cout << rank;
            return 0;
        }
        if(m == a) {
            cnt++;
            continue;
        }
        else {
            cnt = 0;
        }
        rank++;
    }

    if(rank+cnt > p) {
        cout << -1;
    }
    else {
        cout << rank;
    }

    return 0;
}