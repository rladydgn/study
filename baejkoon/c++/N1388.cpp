#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    int answer = 0;
    for(int i=0; i<n; i++) {
        char c = arr[i][0];
        if(c == '-') answer++;
        for(int j=1; j<m; j++) {
            if(c == '|' && arr[i][j] == '-') {
                c = '-';
                answer++;
            }
            else if(arr[i][j] == '|') c = '|';
        }
    }

    for(int j=0; j<m; j++) {
        char c = arr[0][j];
        if(c == '|') answer++;
        for(int i=1; i<n; i++) {
            if(c == '-' && arr[i][j] == '|') {
                c = '|';
                answer++;
            }
            else if(arr[i][j] == '-') c = '-';
        }
    }

    cout << answer;
    return 0;
}