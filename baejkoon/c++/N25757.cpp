#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    char c;
    cin >> n >> c;
    int need;
    if(c == 'Y') need = 2;
    if(c == 'F') need = 3;
    if(c == 'O') need = 4;

    unordered_map<string, int> m;
    int cnt = 0;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        if(m[s] == 0) {
            m[s]++;
            cnt++;
        }
    }
    int answer = cnt / (need-1);
    cout << answer;

    return 0;
}