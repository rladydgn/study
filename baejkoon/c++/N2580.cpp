#include <iostream>
#include <vector>

using namespace std;

int arr[9][9];
int cnt;
vector<pair<int, int>> v;

// 출력함수. 여러개 경우가 있을 수 있어 cnt로 출력했는지 체크한다.
void print() {
    if(cnt == 1) return;
    cnt++;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void dfs(int idx) {
    if(cnt == 1) return;
    if(idx >= v.size()) {
        print();
        return;
    }

    int check[10] = {0, };

    int r = v[idx].first;
    int c = v[idx].second;

    // 가로, 세로 값들을 확인한다.
    for(int i=0; i<9; i++) {
        check[arr[r][i]]++;
        check[arr[i][c]]++;
    }

    int sr = r/3 * 3;
    int sc = c/3 * 3;

    // 3*3 값들을 확인한다.
    for(int i=sr; i<sr+3; i++) {
        for(int j=sc; j<sc+3; j++) {
            check[arr[i][j]]++;
        }
    }

    // check[i]가 0이면 해당 값은 r, c 좌표에 들어갈 수 있는 값이다.
    for(int i=1; i<10; i++) {
        if(check[i] == 0) {
            arr[r][c] = i;
            dfs(idx+1);
            arr[r][c] = 0;
        }
    }
}

int main() {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 0)
                v.push_back({i, j});
        }
    }

    dfs(0);

    return 0;
}