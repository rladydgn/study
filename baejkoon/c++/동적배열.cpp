#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        vector<int> arr_cnt(101, 0);
        vector<int> arr_size(101, 2);
        int answer = 0;
        int n;
        cin >> n;
        for(int j=0; j<n; j++) {
            int a, c;
            cin >> a >> c;
            if(arr_size[a] < arr_cnt[a]+c)
                answer += arr_cnt[a];
            while(arr_size[a] < arr_cnt[a]+c) {
                arr_size[a] *= 2;
            }
            arr_cnt[a] += c;
        }
        cout << answer << "\n";
    }
}