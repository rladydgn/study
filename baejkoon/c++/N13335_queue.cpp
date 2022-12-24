#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, w, l;
    cin >> n >> w >> l;
    int truck[n];
    for(int i=0; i<n; i++)
        cin >> truck[i];

    queue<int> q;
    for(int i=0; i<w; i++)
        q.push(0);
    int sum = 0;
    int idx = 0;
    int answer = 0;
    while(idx < n) {
        int a = q.front();
        q.pop();

        sum -= a;

        if(sum + truck[idx] <= l) {
            sum += truck[idx];
            q.push(truck[idx++]);
        }
        else {
            q.push(0);
        }
        answer++;
    }

    while(sum != 0) {
        sum -= q.front();
        q.pop();
        answer++;
    }

    cout << answer;
}