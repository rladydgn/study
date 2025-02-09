#include <iostream>

using namespace std;

int point[10];
int answer;

void Dfs(int cnt, int b, int bb, int n_p) {
    if(cnt == 10) {
        if(n_p >= 5)
            answer++;
        return;
    }
    for(int i=1; i<=5; i++) {
        if(b == bb && bb == i) continue;
        if(point[cnt] == i) {
            Dfs(cnt+1, i, b, n_p+1);
        }
        else {
            Dfs(cnt+1, i, b, n_p);
        }
    }
}

int main() {
    for(int i=0; i<10; i++)
        cin >> point[i];

    Dfs(0, 0, 0, 0);

    cout << answer;
    return 0;
}