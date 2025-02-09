#include <iostream>
#include <stack>
using namespace std;

int main() {
    cout.tie(0);
    int n;
    cin >> n;
    char ar[n][51];
    for(int i=0; i<n; i++) {
        cin >> ar[i];
        stack<char> stk;
        for(int j=0; j<51; j++) {
            // if no more string
            if(ar[i][j] == NULL) {
                if(stk.empty())
                    cout << "YES" << "\n";
                else
                    cout << "NO" << "\n";
                break;
            }

            if(ar[i][j] == '(')
                stk.push(ar[i][j]);
            else {
                if(stk.empty()) {
                    cout << "NO" << "\n";
                    break;
                }
                else
                    stk.pop();
            }
        }
    }

}
