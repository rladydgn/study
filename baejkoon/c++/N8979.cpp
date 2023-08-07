#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>& v1, vector<int>& v2) {
    if(v1[0] > v2[0])
        return true;
    if(v1[0] == v2[0] && v1[1] > v2[1])
        return true;
    if(v1[0] == v2[0] && v1[1] == v2[1] && v1[2] > v2[2])
        return true;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v;
    for(int i=0; i<n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v.push_back({b, c, d, a});
    }

    sort(v.begin(), v.end(), cmp);

    int answer = 1;
    int cnt = 1;
    if(v[0][3] == m) {
        cout << answer;
        return 0;
    }
    for(int i=1; i<v.size(); i++) {
        if(v[i-1][0] == v[i][0] && v[i-1][1] == v[i][1] && v[i-1][2] == v[i][2]) {
            cnt++;
        }
        else {
            answer += cnt;
            cnt = 1;
        }
        if(v[i][3] == m) {
            break;
        }
    }

    cout << answer;
    return 0;
}