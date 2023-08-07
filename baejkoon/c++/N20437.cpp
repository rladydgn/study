#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int arr[26] = {0, };
        string s;
        int n;
        cin >> s >> n;
        for(int i=0; i<s.size(); i++)
            arr[s[i]-'a']++;
        
        int shortest = 999999;
        int longest = 0;
        for(int i=0; i<s.size(); i++) {
            if(arr[s[i]-'a'] < n) continue;
            
            int cnt = 0;
            for(int j=i; j<s.size(); j++) {
                if(s[j] == s[i]) cnt++;

                if(cnt == n) {
                    shortest = min(shortest, j-i+1);
                    longest = max(longest, j-i+1);
                    break;
                }
            }
        }
        if(shortest == 999999) {
            cout << "-1\n";
        }
        else {
            cout << shortest << " " << longest << "\n";
        }
    }
    return 0;
}