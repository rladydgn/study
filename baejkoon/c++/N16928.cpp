#include <iostream>
#include <queue>

using namespace std;

int arr[101];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n + m; i++) {
        int a, b;
        cin >> a >> b;
        arr[a] = b;
    }

    queue<pair<int, int>> q;
    q.push({1, 0});
    // 방문체크
    arr[1] = -1;

    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;

        q.pop();

        if(a == 100) {
            cout << b;
            return 0;
        }
        
        for(int i=1; i<=6; i++) {
            if(a+i <= 100 && arr[a+i] != -1) {
                // 뱀 or 사다리
                if(arr[a+i] != 0) {
                    q.push({arr[a+i], b+1});
                    arr[arr[a+i]] = -1;
                }
                else {
                    q.push({a+i, b+1});
                    arr[a+i] = -1;
                }
            }
        }
    }

    return 0;
}