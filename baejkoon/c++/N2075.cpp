#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    priority_queue<int> pq;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int tmp;
            cin >> tmp;
            pq.push(-tmp);
        }
        while(pq.size() > n)
            pq.pop();
    }

    int answer = -pq.top();

    cout << answer;

    return 0;
}