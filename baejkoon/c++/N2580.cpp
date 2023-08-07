#include <iostream>
#include <vector>

using namespace std;

int arr[9][9];
int cnt;
vector<pair<int, int>> v;

// ����Լ�. ������ ��찡 ���� �� �־� cnt�� ����ߴ��� üũ�Ѵ�.
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

    // ����, ���� ������ Ȯ���Ѵ�.
    for(int i=0; i<9; i++) {
        check[arr[r][i]]++;
        check[arr[i][c]]++;
    }

    int sr = r/3 * 3;
    int sc = c/3 * 3;

    // 3*3 ������ Ȯ���Ѵ�.
    for(int i=sr; i<sr+3; i++) {
        for(int j=sc; j<sc+3; j++) {
            check[arr[i][j]]++;
        }
    }

    // check[i]�� 0�̸� �ش� ���� r, c ��ǥ�� �� �� �ִ� ���̴�.
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