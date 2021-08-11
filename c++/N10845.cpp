#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int que[10000];
    int bottom = 0;
    int top = 0;

    for(int i=0; i<n; i++) {
        string tmp;
        cin >> tmp;
        if(tmp == "push") {
            int num;
            cin >> num;
            que[top++] = num;
        }
        else if(tmp == "pop") {
            if(bottom == top)
                cout << -1 << "\n";
            else
                cout << que[bottom++] << "\n";
        }
        else if(tmp == "size")
            cout << top-bottom << "\n";
        else if(tmp == "empty") {
            if(bottom == top)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if(tmp == "front") {
            if(bottom == top)
                cout << -1 << "\n";
            else
                cout << que[bottom] << "\n";
        }
        else {
            if(bottom == top)
                cout << -1 << "\n";
            else
                cout << que[top-1] << "\n";
        }
    }
    return 0;
}
