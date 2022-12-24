#include <iostream>
#include <string>
#include <queue>

using namespace std;

char arr[200][200];

int main() {
    // Å¥°¡ ¾Æ´Ï¶ó ¹è¿­À» ÀÌ¿ëÇÏ¸é ´õ ºü¸§.
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int r, c, n;
    cin >> r >> c >> n;
    queue<pair<int, int>> q;
    for(int i=0; i<r; i++) {
        string s;
        cin >> s;
        for(int j=0; j<s.size(); j++) {
            arr[i][j] = s[j];
            if(arr[i][j] == 'O')
                q.push({i, j});
        }
    }

    int t = 1;
    while(t++ < n) {
        // ÆøÅº ¼³Ä¡
        if(t%2 == 0) {
            for(int i=0; i<r; i++)
                for(int j=0; j<c; j++)
                    arr[i][j] = 'O';
        }
        // ÆøÅº ÆøÆÄ
        else {
            while(!q.empty()) {
                int a = q.front().first;
                int b = q.front().second;
                q.pop();

                int y[] = {0, 0, 1, -1};
                int x[] = {1, -1, 0, 0};
                for(int i=0; i<4; i++) {
                    int dy = a + y[i];
                    int dx = b + x[i];

                    if(dy>=0 && dy<r && dx>=0 && dx<c)
                        arr[dy][dx] = '.';
                }
                arr[a][b] = '.';
            }

            for(int i=0; i<r; i++) {
                for(int j=0; j<c; j++) {
                    if(arr[i][j] == 'O')
                        q.push({i, j});
                }
            }
        }
    }

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++)
            cout << arr[i][j];
        cout << "\n";
    }

    return 0;
}