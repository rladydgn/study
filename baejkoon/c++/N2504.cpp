#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string s;
    cin >> s;
    int answer = 0;
    stack<int> st;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '(') {
            st.push(-1);
        }
        else if(s[i] == '[') {
            st.push(-2);
        }
        else if(st.empty()) {
            cout << 0;
            return 0;
        }
        else {
            if(st.top() == -1 && s[i] == ')') {
                st.pop();
                st.push(2);
            }
            else if(st.top() == -2 && s[i] == ']') {
                st.pop();
                st.push(3);
            }
            else {
                int tmp = 0;
                while(st.top() != -1 && st.top() != -2) {
                    tmp += st.top();
                    st.pop();

                    if(st.empty()) {
                        cout << 0;
                        return 0;
                    }
                }
                if(st.top() == -1 && s[i] == ')') {
                    tmp *= 2;
                    st.pop();
                }
                else if(st.top() == -2 && s[i] == ']') {
                    tmp *= 3;
                    st.pop();
                }
                else {
                    cout << 0;
                    return 0;
                }
                st.push(tmp);
            }
        }
    }
    while(!st.empty()) {
        if(st.top() == -1 || st.top() == -2) {
            cout << 0;
            return 0;
        }
        answer += st.top();
        st.pop();
    }

    cout << answer;
    return 0;
}