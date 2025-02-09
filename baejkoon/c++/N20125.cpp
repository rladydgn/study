#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    char arr[n][n];
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<n; j++)
            arr[i][j] = s[j];
    }
    
    int x, y;
    int answer[] = {0, 0, 0, 0, 0};
    for(int i=1; i<n-1; i++) {
        for(int j=1; j<n-1; j++) {
            if(arr[i][j] == '*' && arr[i-1][j] == '*' && arr[i][j-1] == '*' && arr[i+1][j] == '*' && arr[i][j+1] == '*') {
                x = i;
                y = j;
            }
        }
    }
    cout << x+1 << " " << y+1 << "\n";

    for(int j=y-1; j>=0; j--) {
        if(arr[x][j] == '*') answer[0]++;
        else break;
    }
    for(int j=y+1; j<n; j++) {
        if(arr[x][j] == '*') answer[1]++;
        else break;
    }

    for(int i=x+1; i<n; i++) {
        if(arr[i][y] == '*') answer[2]++;
        else {
            x = i;
            break;
        }
    }

    for(int i=x; i<n; i++) {
        if(arr[i][y-1] == '*') answer[3]++;
        else break;
    }

    for(int i=x; i<n; i++) {
        if(arr[i][y+1] == '*') answer[4]++;
        else break;
    }
    
    for(int i=0; i<5; i++)
        cout << answer[i] << " ";

    return 0;
}