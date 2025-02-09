#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int arr[101][101];
int r_size = 3, c_size = 3;
int r, c, k;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if(a.second < b.second) return true;
    if(a.second == b.second && a.first < b.first) return true;
    return false;
}

void cal_r() {
    // 행 개수 최대값
    int m = 0;
    for(int i=1; i<=r_size; i++) {
        unordered_map<int, int> um;
        for(int j=1; j<=c_size; j++) {
            if(arr[i][j] == 0) continue;
            um[arr[i][j]]++;
        }
        // 숫자, 등장 횟수
        vector<pair<int, int>> v;
        for(auto iter=um.begin(); iter != um.end(); iter++) {
            v.push_back({iter->first, iter->second});
        }
        m = max(m, int(v.size())*2);
        sort(v.begin(), v.end(), cmp);

        for(int j=0; j<v.size(); j++) {
            // 100 초과인 경우
            if(j >= 50) break;
            arr[i][j*2+1] = v[j].first;
            arr[i][j*2+2] = v[j].second;
        }
        // 0 으로
        for(int j=v.size()*2+1; j<=100; j++) {
            arr[i][j] = 0;
        }
    }
    c_size = min(100, m);
}

void cal_c() {
    // 열 개수 최대값
    int m = 0;
    for(int i=1; i<=c_size; i++) {
        unordered_map<int, int> um;
        for(int j=1; j<=r_size; j++) {
            if(arr[j][i] == 0) continue;
            um[arr[j][i]]++;
        }
        // 숫자, 등장 횟수
        vector<pair<int, int>> v;
        for(auto iter=um.begin(); iter != um.end(); iter++) {
            v.push_back({iter->first, iter->second});
        }
        m = max(m, int(v.size()*2));
        sort(v.begin(), v.end(), cmp);

        for(int j=0; j<v.size(); j++) {
            // 100 초과인 경우
            if(j >= 50) break;
            arr[j*2+1][i] = v[j].first;
            arr[j*2+2][i] = v[j].second;
        }
        // 0 으로
        for(int j=v.size()*2+1; j<=100; j++) {
            arr[j][i] = 0;
        }
    }
    r_size = min(100, m);
}

int main() {
    cin >> r >> c >> k;
    for(int i=1; i<=3; i++) {
        for(int j=1; j<=3; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<101; i++) {
        if(arr[r][c] == k) {
            cout << i;
            return 0;
        }

        if(r_size >= c_size) {
            cal_r();
        }
        else {
            cal_c();
        }

        // for(int a=1; a<=5; a++) {
        //     for(int b=1; b<=5; b++) {
        //         cout << arr[a][b] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << r_size << " " << c_size;
        // cout << endl;
    }

    cout << -1;
    return 0;
}