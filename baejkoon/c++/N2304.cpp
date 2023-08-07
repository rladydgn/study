#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    int idx = 0;
    int answer = 0;
    while(idx < v.size()) {
        int max_ = 0;
        int idx2 = 0;
        for(int i=idx+1; i<v.size(); i++) {
            if(max_ < v[i].second) {
                max_ = v[i].second;
                idx2 = i;
            }

            if(v[idx].second < max_) {
                answer = answer + (v[idx2].first-v[idx].first)*v[idx].second;
                idx = idx2;
                break;
            }
        }
        if(max_ == 0) break;

        answer = answer + (v[idx2].first-v[idx].first-1)*v[idx2].second + v[idx].second;
        idx = idx2;
    }
    cout << answer + v[n-1].second;
    return 0;
}