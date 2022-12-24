#include <iostream>
#include <stack>
#include <string>

using namespace std;

string answer;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;

    stack<int> st;
    int now = 0;

    for(int i=0; i<n; i++) {
        int x;
        cin >> x;

        while(now < x) {
            now++;
            st.push(now);
            answer += "+\n";
        }

        if(st.top() == x) {
            st.pop();
            answer += "-\n";
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    cout << answer;

    return 0;
}