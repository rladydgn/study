#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        int n;
        cin >> n;
        map<string, int> m;
        for(int j=0; j<n; j++) {
            string a, b;
            cin >> a >> b;
            m[b] += 1;
        }
        int answer = 1;
        for(auto iter = m.begin(); iter != m.end(); iter++) {
            answer = answer * (iter->second + 1);
        }
        cout << answer-1 << "\n";
    }
    return 0;
}