#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    int answer = 0, sum = 0;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
        if(i>=1) {
            sum = sum + abs(a-v[i-1].first) + abs(b-v[i-1].second);
        }
    }
    answer = sum;

    for(int i=1; i<n-1; i++) {
        int tmp = sum;
        tmp = tmp - (abs(v[i].first-v[i-1].first) + abs(v[i].second-v[i-1].second)
        + abs(v[i+1].first-v[i].first) + abs(v[i+1].second-v[i].second));
        tmp = tmp + abs(v[i+1].first-v[i-1].first) + abs(v[i+1].second-v[i-1].second);
        answer = min(answer, tmp);
    }
    cout << answer;

    return 0;
}