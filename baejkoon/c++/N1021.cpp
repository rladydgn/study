#include <deque>
#include <iostream>

using namespace std;

int main() {
    int n, m;
    int answer = 0;
    cin >> n >> m;
    deque<int> dq;
    for(int i=0; i<n; i++) {
        dq.push_back(i+1);
    }
    for(int i=0; i<m; i++) {
        int k;
        cin >> k;
        int idx;
        for(int j=0; j<dq.size(); j++) {
            if(dq[j] == k) {
                idx = j;
                break;
            }
        }

        if(idx < dq.size()-idx) {
            while(true) {
                if(dq.front() == k) {
                    dq.pop_front();
                    break;
                }
                answer++;
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            while(true) {
                if(dq.front() == k) {
                    dq.pop_front();
                    break;
                }
                answer++;
                dq.push_front(dq.back());
                dq.pop_back();
            }

        }
    }
    cout << answer;

    return 0;
}