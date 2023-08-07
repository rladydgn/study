#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<long long int> pq;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        pq.push(-tmp);
    }

    for(int i=0; i<m; i++) {
        long long int a = pq.top();
        pq.pop();
        long long int b = pq.top();
        pq.pop();

        pq.push(a+b);
        pq.push(a+b);
    }

    long long int answer = 0;
    while(!pq.empty()) {
        answer -= pq.top();
        pq.pop();
    }
    cout << answer;

    return 0;
}