#include <iostream>
#include <queue>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    queue<pair<int, int>> q;
    q.push({a, 0});
    while(!q.empty()) {
        long long int n = q.front().first;
        long long int m = q.front().second;
        q.pop();

        // cout << n << " " << m << endl;

        if(n == b) {
            cout << m+1;
            return 0;
        }

        if(n*10+1 <= b)
            q.push({n*10+1, m+1});
        if(n*2 <= b)
            q.push({n*2, m+1});
    }

    cout << -1;
    return 0;
}