#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(pair<string ,int> &a, pair<string, int> &b) {
    if(a.second > b.second) return true;
    if(a.second == b.second && a.first.size() > b.first.size()) return true;
    if(a.second == b.second && a.first.size() == b.first.size() && a.first < b.first) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    unordered_map<string ,int> um;

    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        if(s.size() >= m) {
            um[s]++;
        }
    }

    vector<pair<string, int>> v;
    for(auto iter=um.begin(); iter != um.end(); iter++) {
        v.push_back({iter->first, iter->second});
    }

    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<v.size(); i++) {
        cout << v[i].first << "\n";
    }
    return 0;
}