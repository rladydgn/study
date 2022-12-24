#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int n, k;
    
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> k;
        priority_queue<long long int> hq, lq;
        unordered_map<long long int, long long int> um;
        for(int j=0; j<k; j++) {
            char c;
            cin >> c;
            // 삽입 
            if(c == 'I') {
                long long int tmp;
                cin >> tmp;
                um[tmp]++;
                hq.push(tmp);
                lq.push(-tmp);
            }
            // 삭제 
            if(c == 'D') {
                int tmp;
                cin >> tmp;
                if(tmp == 1 && !hq.empty()) {
                    int rm = hq.top();
                    um[rm]--;
                    hq.pop();
                }
                else if(tmp == -1 && !lq.empty()) {
                    int rm = -lq.top();
                    um[rm]--;
                    lq.pop();
                }
                // 맨 앞 값이 이미 삭제된 값인지 확인 
                while(!lq.empty()) {
                    if(um[-lq.top()] == 0)
                        lq.pop();
                    else
                        break;
                }
                while(!hq.empty()) {
                    if(um[hq.top()] == 0)
                        hq.pop();
                    else
                        break;
                }
            }
        }
        if(hq.empty() && lq.empty()) {
            cout << "EMPTY" << "\n";
        }
        else {
            cout << hq.top() << " " << -lq.top() << "\n";
        }
    }
    return 0;
}
