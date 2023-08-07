#include <iostream>
#include <deque>

using namespace std;

deque<pair<int, int>> dq;
int arr[101][101];
int n;

bool check(pair<int, int> cor) {
    // �� �浹 üũ
    if(cor.first<=0 || cor.first>n || cor.second<=0 || cor.second>n) {
        return true;
    }

    // �� �浹 üũ
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
    // ���
    for(int i=0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }

    int l;
    cin >> l;
    // �� - 0, �� - 1, �� - 2, �� - 3
    int dir = 1;
    int time = 0;
    dq.push_back({1, 1});
    for(int i=0; i<l; i++) {
        int a;
        char b;
        cin >> a >> b;
        
        // ���� �̵�
        while(time<=a || i==l-1) {
            pair<int, int> cor;

            // �� �� �̵�
            if(time == a) {
                if(b == 'D') dir = (dir+1)%4;
                else {
                    if(dir == 0) dir = 3;
                    else dir -= 1;
                }
            }  

            // ���� �̵�
            if(dir == 1)
                cor = {dq.back().first, dq.back().second+1};
            else if(dir == 2)
                cor = {dq.back().first+1, dq.back().second};
            else if(dir == 3)
                cor = {dq.back().first, dq.back().second-1};
            else
                cor = {dq.back().first-1, dq.back().second};
            time++;
            
            // �浹 üũ
            if(check(cor)) {
                cout << time;
                return 0;
            }

            dq.push_back(cor);
            // ��� üũ
            if(arr[cor.first][cor.second] != 1) {
                dq.pop_front();
            }
            else {
                arr[cor.first][cor.second] = 0;
            }

        }
    }
}