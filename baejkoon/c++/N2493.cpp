#include <iostream>
#include <stack>

using namespace std;

int answer[500000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    stack<pair<int, int>> s1, s2;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        s1.push({i+1, tmp});
    }

    s2.push(s1.top());
    s1.pop();

    while(!s1.empty()) {
        if(!s2.empty() && s1.top().second > s2.top().second) {
            answer[s2.top().first-1] = s1.top().first;
            s2.pop();
        }
        else {
            s2.push(s1.top());
            s1.pop();
        }
    }
    for(int i=0; i<n; i++)
        cout << answer[i] << " ";
    
    return 0;
}