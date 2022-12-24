#include <iostream>
#include <queue>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        int n, m;
        cin >> n >> m;
        queue<int> q;
        priority_queue<int> pq;
        int v;
        for(int j=0; j<n; j++) {
            int tmp;
            cin >> tmp;
            q.push(tmp);
            pq.push(tmp);
            if(j == m)
                v = tmp;
        }

        int answer = 1;
        while(true) {
            int a = q.front();
            q.pop();

            if(m == 0 && a == pq.top()) {
                cout << answer << "\n";
                break;
            }

            if(a == pq.top()) {
                answer++;
                pq.pop();
            }
            else {
                q.push(a);
            }

            if(m == 0) {
                m = q.size()-1;
            }
            else {
                m--;
            }
        }
    }
}