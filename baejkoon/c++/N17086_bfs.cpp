#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    vector<pair<int, int>> sharks;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1)
                sharks.push_back({i, j});
        }
    }

    int answer = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int min_ = 99999999;
            for(int k=0; k<sharks.size(); k++) {
                int tmp = 0;
                int a = abs(sharks[k].first - i);
                int b = abs(sharks[k].second - j);
                if(a>0 && b>0) {
                    tmp += min(a, b);
                    tmp += abs(a-b);
                }
                else {
                    tmp += a + b;
                }
                if(min_ > tmp)
                    min_ = tmp;
            }
            if(min_ > answer)
                answer = min_;
        }
    }

    cout << answer;
}