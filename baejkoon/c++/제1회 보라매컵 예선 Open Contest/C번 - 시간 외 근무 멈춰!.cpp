#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    int answer = 0;
    int normal = 0;
    int special = 0;
    int idx = 0;
    for(int i=1; i<=v[n-1].first; i++) {
        if(i%7 == 6 || i%7 == 0) normal--;
        normal++;
        special++;

        while(v[idx].first == i) {
            normal = normal - v[idx].second;
            if(normal < 0) {
                special += normal;
                if(special < 0) {
                    cout << -1;
                    return 0;
                }
                answer -= normal;
                normal = 0;
            }
            idx++;
        }
    }

    cout << answer;

    return 0;
}