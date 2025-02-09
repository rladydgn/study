#include <iostream>

using namespace std;

int arr[500][500];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, b;
    cin >> n >> m >> b;
    int minv = 9999, maxv = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
            minv = min(arr[i][j], minv);
            maxv = max(arr[i][j], maxv);
        }
    }

    int time = 99999999;
    int hight = 0;
    for(int i=minv; i<=maxv; i++) {
        int time_tmp = 0;
        int blocks = 0;
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) {
                if(arr[j][k] > i) {
                    time_tmp = time_tmp + (arr[j][k]-i) * 2;
                }
                else {
                    time_tmp = time_tmp + i - arr[j][k];
                }
                blocks = blocks + arr[j][k] - i;
            }
        }

        if(b+blocks >= 0 && time >= time_tmp) {
            time = time_tmp;
            hight = i;
        }
    }

    cout << time << " " << hight;
    return 0;
}