#include <iostream>
#include <cmath>

using namespace std;

int arr[20001];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        arr[tmp+10000] = 1;
    }

    int max_value = 0;
    int cnt = 0;
    int tmp = 0;
    int answer = 0;
    for(int i=9999; i>=0; i--) {
        if(arr[i] == 1) {
            cnt++;
            tmp = 10000-i;
            max_value = 10000-i;
        }

        if(cnt == m) {
            cnt = 0;
            answer = answer + tmp*2;
        }
    }
    if(cnt != 0) {
        answer = answer + tmp*2;
    }

    int max_value2 = 0;
    cnt = 0;
    tmp = 0;

    for(int i=10001; i<=20000; i++) {
        if(arr[i] == 1) {
            cnt++;
            tmp = i-10000;
            max_value2 = i-10000;
        }

        if(cnt == m) {
            cnt = 0;
            answer = answer = tmp*2;
        }
    }
    if(cnt != 0) {
        answer = answer + tmp*2;
    }

    if(max_value > max_value2) {
        answer -= max_value;
    }
    else {
        answer -= max_value2;
    }
    cout << answer;
    return 0;
}