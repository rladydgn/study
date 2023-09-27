#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if(a.first < b.first) return true;
    else if(a.first == b.first && a.second > b.second) return true;
    return false;
}

int main() {
    int d, n;
    cin >> d >> n;
    int arr[d];
    vector<pair<int, int>> oven;
    for(int i=0; i<d; i++) {
        cin >> arr[i];
        oven.push_back({arr[i], i+1});
    }
    sort(oven.begin(), oven.end(), cmp);

    int to = d;
    int from = 0;
    int answer = d;
    for(int i=0; i<n; i++) {
        int k;
        cin >> k;
        bool check = false;
        for(int j=from; j<d; j++) {
            if(oven[j].first >= k) {
                from = j;
                answer = to;
                to = to-1;
                check = true;
                // cout << oven[j].first << " " << oven[j].second << " " << from << " " << answer << " " << to << endl;
                break;
            }
            to = min(to, oven[j].second-1);
        }
        if(to < 0 || !check) {
            cout << 0;
            return 0;
        }
    }

    cout << answer;
    return 0;
}