#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if(a.second < b.second)
        return true;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    // 추천수, 학생번호
    vector<pair<int, int>> v;
    for(int i=0; i<m; i++) {
        int c;
        cin >> c;
        bool check = true;
        // vector에 값이 이미 들어가 있는 경우를 찾음
        for(int j=0; j<v.size(); j++) {
            if(v[j].second == c) {
                v[j].first++;
                check = false;
                break;
            }
        }

        // vector에 값이 들어가 있지 않은 경우
        if(check) {
            // 등록된 그림수 보다 vector의 사이즈가 작은경우
            if(v.size() < n) {
                v.push_back({1, c});
            }
            // 등록된 그림수 보다 vector의 사이즈가 크거나 같은경우
            else {
                int mini = 9999999;
                int idx = 9999;
                // 가장 추천수가 작은 늦게 들어온 학생을 찾는다.
                for(int j=0; j<v.size(); j++) {
                    if(v[j].first < mini) {
                        mini = v[j].first;
                        idx = j;
                    }
                }
                v.erase(v.begin() + idx);
                v.push_back({1, c});
            }
        }
    }

    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<v.size(); i++)
        cout << v[i].second << " ";

    return 0;
}