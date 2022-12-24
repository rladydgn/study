#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<int, int> mp, mp2;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    if(a.first > b.first)
        return true;
    else if(a.first < b.first)
        return false;
    else {
        if(mp2[a.second] < mp2[b.second])
            return true;
        return false;
    }
}

int main() {
    int n, c;
    cin >> n >> c;

    int check = 1;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        mp[tmp]++;

        if(mp2[tmp] == 0)
            mp2[tmp] = check++;
    }

    vector<pair<int, int>> v;
    for(auto iter = mp.begin(); iter != mp.end(); iter++) {
        v.push_back({iter->second, iter->first});
    }

    sort(v.begin(), v.end(), compare);

    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v[i].first; j++) {
            cout << v[i].second << " ";
        }
    }

    return 0;
}