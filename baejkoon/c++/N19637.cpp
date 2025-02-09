#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<pair<string, int>> v;
    v.reserve(100000);
    string s;
    int a;
    cin >> s >> a;
    v.push_back({s, a});
    for(int i=1; i<n; i++) {
        cin >> s >> a;
        if(v.back().second == a) continue;
        v.push_back({s, a});
    }

    for(int i=0; i<m; i++) {
        int power;
        cin >> power;
        int low = 0;
        int high = v.size()-1;
        int middle = (low+high)/2;
        while(low < high) {
            if(v[middle].second < power) {
                low = middle + 1;
            } 
            else if(v[middle].second > power) {
                high = middle - 1;
            }
            else break;
            middle = (low+high)/2;
        }
        if(v[middle].second >= power) {
            cout << v[middle].first << "\n";
        }
        else {
            cout << v[middle+1].first << "\n";
        }
    }
    return 0;
}