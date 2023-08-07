#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if(a.first > b.first)
        return true;
    if(a.first == b.first && a.second > b.second)
        return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    vector<pair<int, int>> v2 = v;
    sort(v2.begin(), v2.end(), cmp);
    
    map<pair<int, int>, int> m;
    int rank = 1;
    int cnt = 1;
    m[v2[0]] = 1;
    int min_tall = v2[0].second;

    for(int i=0; i<n; i++) {
        cout << v2[i].first << " " << v2[i].second << endl;
    }

    for(int i=1; i<n; i++) {
        if(v2[i-1].first == v2[i].first || v2[i].second >= min_tall) {
            m[v2[i]] = rank;
            cnt++;
        }
        else {
            m[v2[i]] = rank + cnt;
            rank += cnt;
            cnt = 1;
            min_tall = v2[i].second;
        }
    }
    for(int i=0; i<n; i++) {
        cout << m[v[i]] << " ";
    }
}