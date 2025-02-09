#include <iostream>

using namespace std;

int main() {
    int v, e;
    cin >> v >> e;
    int arr[v+1][v+1];

    for(int i=1; i<=v; i++)
        for(int j=1; j<=v; j++)
            arr[i][j] = 99999999;

    for(int i=0; i<e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = c;
    }

    int answer = 99999999;
    for(int k=1; k<=v; k++) {
        for(int i=1; i<=v; i++) {
            for(int j=1; j<=v; j++) {
                arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j]);
                if(i == j) {
                    answer = min(answer, arr[i][j]);
                }
            }
        }
    }
    if(answer == 99999999)
        cout << -1;
    else
        cout << answer;
    return 0;
}