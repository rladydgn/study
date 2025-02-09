#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0);
    int deq[20000] = {0, };
    int n, in;
    int fnt = 10000, top = 10000;
    cin >> n;
    for(int i=0; i<n; i++) {
        string tmp;
        cin >> tmp;
        if(tmp == "push_front") {
            cin >> in;
            deq[fnt--] = in;
        }
        else if(tmp == "push_back") {
            cin >> in;
            deq[++top] = in;
        }
        else if(tmp == "pop_front") {
            if(fnt == top)
                cout << -1 << "\n";
            else
                cout << deq[++fnt] << "\n";
        }
        else if(tmp == "pop_back") {
            if(fnt == top)
                cout << -1 << "\n";
            else
                cout << deq[top--] << "\n";
        }
        else if(tmp == "size")
            cout << top-fnt << "\n";
        else if(tmp == "empty") {
            if(top-fnt)
                cout << 0 << "\n";
            else
                cout << 1 << "\n";
        }
        else if(tmp == "front") {
            if(fnt == top)
                cout << -1 << "\n";
            else
                cout << deq[fnt+1] << "\n";
        }
        else {
            if(fnt == top)
                cout << -1 << "\n";
            else
                cout << deq[top] << "\n";
        }
    }
    return 0;
}
