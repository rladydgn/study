#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    string s[n], s2[m];
    for(int i=0; i<n; i++)
        cin >> s[i];
    for(int i=0; i<m; i++)
        cin >> s2[i];

    sort(s, s+n);
    sort(s2, s2+m);

    int idx = 0, idx2 = 0;
    int answer = 0;
    while(idx < n && idx2 < m) {
        if(s[idx] < s2[idx2])
            idx++;
        else if(s[idx] > s2[idx2])
            idx2++;
        else {
            idx2++; answer++;
        }
    }

    cout << answer;

    return 0;
}