#include <map>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    map<int, int> m;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        m[tmp] = 1;
    }
    cin >> n;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        if(m[tmp])
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
    return 0;
}
