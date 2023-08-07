#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int visited[10000];

int main() {
    int arr[4];
    for(int i=0; i<4; i++)
        cin >> arr[i];
    
    int min_ = 10000;
    for(int i=0; i<4; i++) {
        int tmp = 0;
        for(int j=0; j<4; j++) {
            tmp = tmp + arr[(i+j)%4]*pow(10, 3-j);
        }
        min_ = min(min_, tmp);
    }
    // cout << min_ << endl << endl;
    int answer = 0;
    for(int i=1; i<=9; i++) {
        for(int j=1; j<=9; j++) {
            for(int k=1; k<=9; k++) {
                for(int l=1; l<=9; l++) {
                    int a = i*1000+j*100+k*10+l;
                    int b = j*1000+k*100+l*10+i;
                    int c = k*1000+l*100+i*10+j;
                    int d = l*1000+i*100+j*10+k;
                    int m = min({a, b, c, d});
                    if(m == min_) {
                        cout << answer+1;
                        return 0;
                    }
                    if(!visited[m]) {
                        visited[m]++;
                        answer++;
                    }
                }
            }
        }
    }

    return 0;
}