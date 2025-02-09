#include <iostream>
#include <deque>

using namespace std;

deque<pair<int, int>> dq;
int arr[101][101];
int n;

bool check(pair<int, int> cor) {
    // 벽 충돌 체크
    if(cor.first<=0 || cor.first>n || cor.second<=0 || cor.second>n) {
        return true;
    }

    // 몸 충돌 체크
    for(int i=0; i<dq.size(); i++) {
        if(cor.first == dq[i].first && cor.second == dq[i].second) {
            return true;
        }
    }
    return false;
}

int main() {
    int k;
    cin >> n >> k;
    // 사과
    for(int i=0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }

    int l;
    cin >> l;
    // 상 - 0, 우 - 1, 하 - 2, 좌 - 3
    int dir = 1;
    int time = 0;
    dq.push_back({1, 1});
    for(int i=0; i<l; i++) {
        int a;
        char b;
        cin >> a >> b;
        
        // 직선 이동
        while(time<=a || i==l-1) {
            pair<int, int> cor;

            // 우 좌 이동
            if(time == a) {
                if(b == 'D') dir = (dir+1)%4;
                else {
                    if(dir == 0) dir = 3;
                    else dir -= 1;
                }
            }  

            // 직선 이동
            if(dir == 1)
                cor = {dq.back().first, dq.back().second+1};
            else if(dir == 2)
                cor = {dq.back().first+1, dq.back().second};
            else if(dir == 3)
                cor = {dq.back().first, dq.back().second-1};
            else
                cor = {dq.back().first-1, dq.back().second};
            time++;
            
            // 충돌 체크
            if(check(cor)) {
                cout << time;
                return 0;
            }

            dq.push_back(cor);
            // 사과 체크
            if(arr[cor.first][cor.second] != 1) {
                dq.pop_front();
            }
            else {
                arr[cor.first][cor.second] = 0;
            }

        }
    }
}