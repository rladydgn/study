#include <iostream>
#include <string>

using namespace std;

int arr[50][50];
int answer, n;

void findr(int r) {
    int candy = arr[r][0];
    int cnt = 1;
    for(int i=1; i<n; i++) {
        if(candy == arr[r][i]) {
            cnt++;
        }
        else {
            candy = arr[r][i];
            answer = max(answer, cnt);
            cnt = 1;
        }
    }
    answer = max(answer, cnt);
}

void findc(int c) {
    int candy = arr[0][c];
    int cnt = 1;
    for(int i=1; i<n; i++) {
        if(candy == arr[i][c]) {
            cnt++;
        }
        else {
            candy = arr[i][c];
            answer = max(answer, cnt);
            cnt = 1;
        }
    }
    answer = max(answer, cnt);
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<n; j++) {
            arr[i][j] = s[j];
        }
    }

    for(int i=0; i<n; i++) {
        findr(i);
        findc(i);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i+1<n && arr[i][j] != arr[i+1][j]) {
                swap(arr[i][j], arr[i+1][j]);
                findr(i);
                findr(i+1);
                findc(j);
                swap(arr[i][j], arr[i+1][j]);
            }
            if(j+1<n && arr[i][j] != arr[i][j+1]) {
                swap(arr[i][j], arr[i][j+1]);
                findr(i);
                findc(j);
                findc(j+1);
                swap(arr[i][j], arr[i][j+1]);
            }
        }
    }
    cout << answer;

    return 0;
}