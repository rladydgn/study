#include <iostream>
#include <vector>

using namespace std;

int dp[10001];

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        bool check = true;
        for(int j=0; j<v.size(); j++) {
            if(tmp == v[j]) {
                check = false;
                break;
            }
        }
        if(check)
            v.push_back(tmp);
    }

    for(int j=1; j<10001; j++) {
        dp[j] = 99999999;
    }
    
    for(int i=0; i<v.size(); i++) {
        for(int j=1; j<=k; j++) {
            if(j == v[i]) dp[j] = 1;

            if(j-v[i]>0) {
                dp[j] = min(dp[j], dp[j-v[i]]+1);
            }
        }
    }
    // for(int j=1; j<=k; j++) {
    //     cout << dp[j] << " ";
    // }
    if(dp[k] == 99999999) cout << -1;
    else cout << dp[k];
    return 0;
}