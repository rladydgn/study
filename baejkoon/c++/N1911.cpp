#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, l;
    cin >> n >> l;
    vector<pair<int, int>> v;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    int now = 0;
    int answer = 0;
    for(int i=0; i<n; i++) {
        if(now < v[i].first)
            now = v[i].first;
        
        int gap = v[i].second - now;

        if(gap < 0) continue;

        if(gap%l == 0) {
            now = v[i].second;
            answer = answer + gap/l;
        }
        else {
            now = now + gap/l * l + l;
            answer = answer + gap/l + 1;
        }
    }
    cout << answer;

    return 0;
}