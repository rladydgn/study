#include <iostream>
using namespace std;

unsigned int dp[100][10];

/*
void rec(int len, int n) {
    if(len==1)
        return;
    int a = n-1;
    int b = n+1;

    if(a>=0) {
        rec(len-1, a);
        answer++;
    }
    if(b<=9) {
        rec(len-1, b);
        answer++;
    }

}
*/

int main() {
    int n;
    cin >> n;
    for(int i=1; i<10; i++) {
        dp[0][i] = 1;
    }
    for(int i=1; i<n; i++) {
        for(int j=0; j<10; j++) {
            if(j==0)
                dp[i][j] = dp[i-1][j+1];
            else if(j==9)
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
        }
    }
    int answer = 0;
    for(int i=0; i<10; i++) {
        answer = (answer + dp[n-1][i])%1000000000;
    }
    cout << answer;
}
