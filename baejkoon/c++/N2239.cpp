#include <iostream>
#include <vector>
#include <string>

using namespace std;

int arr[9][9];
int cnt;
vector<pair<int, int>> v;

void print() {
    if(cnt == 1) return;
    cnt++;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cout << arr[i][j] << "";
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

    for(int i=0; i<9; i++) {
        check[arr[r][i]]++;
        check[arr[i][c]]++;
    }

    int sr = r/3 * 3;
    int sc = c/3 * 3;

    for(int i=sr; i<sr+3; i++) {
        for(int j=sc; j<sc+3; j++) {
            check[arr[i][j]]++;
        }
    }
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
        string s;
        cin >> s;
        for(int j=0; j<9; j++) {
            arr[i][j] = s[j] - '0';
            if(arr[i][j] == 0)
                v.push_back({i, j});
        }
    }

    dfs(0);

    return 0;
}