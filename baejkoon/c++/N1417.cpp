#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, me;
    cin >> n >> me;
    priority_queue<int> pq;
    for(int i=1; i<n; i++) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    int answer = 0;
    while(!pq.empty()) {
        if(pq.top() < me) break;
        me++;
        int tmp = pq.top();
        tmp--;
        pq.pop();
        pq.push(tmp);
        answer++;
    }

    cout << answer;
    return 0;
}