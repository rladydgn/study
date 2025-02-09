#include <iostream>

using namespace std;

int n;
// 1~9번 선수의 타석 번호
int order[10];
// 타석번호 점유 여부
int check[10];
int answer;
int record[50][10];

// 이닝 진행
void CountPoint() {
    int now_hitter = 1;
    int point = 0;
    for(int i=0; i<n; i++) {
        int base[] = {0, 0, 0, 0};
        int out = 0;
        // cout << i << " inning ";
        while(out != 3) {
            // 아웃
            if(record[i][check[now_hitter]] == 0) {
                out++;
            }
            // 아래 조건문들은 각각 1~3루타, 홈런인 경우
            else if(record[i][check[now_hitter]] == 1) {
                for(int k=3; k>=1; k--) {
                    if(base[k] == 1 && k == 3) {
                        base[k] = 0;
                        point++;
                    }
                    else if(base[k] == 1) {
                        base[k+1] = 1;
                        base[k] = 0;
                    }
                }
                base[1] = 1;
            }
            else if(record[i][check[now_hitter]] == 2) {
                for(int k=3; k>=1; k--) {
                    if(base[k] == 1 && k >= 2) {
                        base[k] = 0;
                        point++;
                    }
                    else if(base[k] == 1) {
                        base[k+2] = 1;
                        base[k] = 0;
                    }
                }
                base[2] = 1;
            }
            else if(record[i][check[now_hitter]] == 3) {
                for(int k=3; k>=1; k--) {
                    if(base[k] == 1) {
                        base[k] = 0;
                        point++;
                    }
                }
                base[3] = 1;
            }
            else if(record[i][check[now_hitter]] == 4) {
                for(int k=3; k>=1; k--) {
                    if(base[k] == 1) {
                        base[k] = 0;
                        point++;
                    }
                }
                point++;
            }
            now_hitter += 1;
            if(now_hitter == 10)
                now_hitter = 1;
        }
        // cout << endl;
    }
    if(point > answer)
        answer = point;
}

// 각 선수의 타순 지정
// 선수 번호
void Dfs(int hitter) {

    if(hitter == 10) {
        CountPoint();
        return;
    }

    for(int i=1; i<10; i++) {
        if(check[i] == 0) {
            order[hitter] = i;
            check[i] = hitter;
            Dfs(hitter+1);
            check[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=1; j<10; j++)
            cin >> record[i][j];
    order[1] = 4;
    check[4] = 1;
    Dfs(2);
    cout << answer;
    return 0;
}