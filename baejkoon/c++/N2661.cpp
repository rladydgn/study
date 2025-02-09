#include <iostream>
#include <string>

using namespace std;
int n;
string answer;

bool check(string s) {
    int len = s.size()/2;
    for(int i=1; i<=len; i++) {
        string a = "", b = "";
        for(int j=s.size()-1; j>s.size()-1-i; j--) {
            a += s[j];
        }
        for(int j=s.size()-1-i; j>(int)s.size()-i*2-1; j--) {
            b += s[j];
        }
        // cout << a << " " << b << endl;
        if(!a.compare(b))
            return false;
    }
    return true;
}

void Dfs(int cnt, string s) {
    if(!answer.empty())
        return;
    if(cnt == n) {
        answer = s;
        cout << answer << endl;
        return;
    }

    if(check(s+"1"))
        Dfs(cnt+1, s+"1");
    if(check(s+"2"))
        Dfs(cnt+1, s+"2");
    if(check(s+"3"))
        Dfs(cnt+1, s+"3");
    
}

int main() {
    cin >> n;

    Dfs(0, "");

    return 0;
}