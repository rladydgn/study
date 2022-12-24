#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    priority_queue<int> pq;
    cin >> n;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        pq.push(-tmp);
    }

    int answer = 0;
    while(true) {
        if(pq.size() == 1) {
            cout << answer;
            return 0;
        }
        int a = -pq.top();
        pq.pop();
        int b = -pq.top();
        pq.pop();
        answer += a + b;
        pq.push(-(a+b));
    }

    return 0;
}