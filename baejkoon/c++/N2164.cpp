#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> q;
    for(int i=1; i<=n; i++)
        q.push(i);

    int answer;
    while(true) {
        answer = q.front();
        q.pop();
        if(q.empty()) break;
        int tmp = q.front();
        q.pop();
        q.push(tmp);
    }
    cout << answer;
    return 0;
}