#include <iostream>
#include <string>

using namespace std;

int visited[20000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int answer = 0;
    for(int i=0; i<n; i++) {
        if(s[i] == 'P') {
            for(int j=i-k; j<=i+k; j++) {
                if(j<0 || j>= n) continue;
                if(visited[j] == 0 && s[j] == 'H') {
                    visited[j] = 1;
                    answer++;
                    break;
                }
            }
        }
    }
    cout << answer;

    return 0;
}