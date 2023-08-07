#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string s;
int answer;

void dfs(string a) {
    if(a.size() == s.size()) {
        if(a == s) answer = 1;
        return;
    }
    if(a[a.size()-1] == 'A') dfs(a.substr(0, a.size()-1));
    if(a[0] == 'B')  {
        a = a.substr(1);
        reverse(a.begin(), a.end());
        dfs(a);
    }
}

int main() {
    string a;
    cin >> s >> a;

    dfs(a);
    cout << answer;
    return 0;
}