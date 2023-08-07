#include <iostream>

using namespace std;

int arr[50][50];
int r, c, t;
int air = -1;

void spread() {
    int sp[r][c];
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            sp[i][j] = 0;

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(arr[i][j] > 0) {
                int cnt = 0;
                if(i+1<r && arr[i+1][j] != -1) {
                    sp[i+1][j] += arr[i][j]/5;
                    cnt++;
                }
                if(i-1>=0 && arr[i-1][j] != -1) {
                    sp[i-1][j] += arr[i][j]/5;
                    cnt++;
                }
                if(j+1<c) {
                    sp[i][j+1] += arr[i][j]/5;
                    cnt++;
                }
                if(j-1>=0 && arr[i][j-1] != -1) {
                    sp[i][j-1] += arr[i][j]/5;
                    cnt++;
                }
                int tmp = arr[i][j]/5;
                sp[i][j] += arr[i][j] - tmp*cnt;
            }
        }
    }
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(arr[i][j] != -1)
                arr[i][j] = sp[i][j];
        }
    }
}

void clean() {
    // 위순환
    int before = 0;
    for(int i=1; i<c; i++) {
        int tmp = arr[air][i];
        arr[air][i] = before;
        before = tmp;
    }
    for(int i=air-1; i>=0; i--) {
        int tmp = arr[i][c-1];
        arr[i][c-1] = before;
        before = tmp;
    }
    for(int i=c-2; i>=0; i--) {
        int tmp = arr[0][i];
        arr[0][i] = before;
        before = tmp;
    }
    for(int i=1; i<air; i++) {
        int tmp = arr[i][0];
        arr[i][0] = before;
        before = tmp;
    }
    // 아래 순환
    before = 0;
    for(int i=1; i<c; i++) {
        int tmp = arr[air+1][i];
        arr[air+1][i] = before;
        before = tmp;
    }
    for(int i=air+2; i<r; i++) {
        int tmp = arr[i][c-1];
        arr[i][c-1] = before;
        before = tmp;
    }
    for(int i=c-2; i>=0; i--) {
        int tmp = arr[r-1][i];
        arr[r-1][i] = before;
        before = tmp;
    }
    for(int i=r-2; i>air+1; i--) {
        int tmp = arr[i][0];
        arr[i][0] = before;
        before = tmp;
    }
}

int main() {
    cin >> r >> c >> t;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == -1 && air == -1)
                air = i;
        }
    }

    for(int i=0; i<t; i++) {
        spread();
        clean();
    }
    int answer = 0;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(arr[i][j] != -1)
                answer += arr[i][j];
        }
    }
    cout << answer;
    return 0;
}