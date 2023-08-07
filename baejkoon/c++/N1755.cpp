#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string arr[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    int m, n;
    cin >> m >> n;
    vector<pair<string, int>> v;
    for(int i=m; i<=n; i++) {
        string s = to_string(i);
        string tmp = "";
        for(int j=0; j<s.size(); j++) {
            tmp += arr[s[j]-'0'];
        }
        v.push_back({tmp, i});
    }
    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++) {
        cout << v[i].second << " ";
        if(i%10==9)
            cout << "\n";
    }
    return 0;
}