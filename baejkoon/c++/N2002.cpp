#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s[n], ss[n];
    for(int i=0; i<n; i++) {
        cin >> s[i];
    }
    for(int i=0; i<n; i++) {
        cin >> ss[i];
    }

    unordered_map<string, unordered_map<string, int>> um;
    for(int i=0; i<n; i++) {
        unordered_map<string, int> tmp;
        um[s[i]] = tmp;
        for(int j=i+1; j<n; j++) um[s[i]][s[j]] = 1;
    }

    int answer = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(um[ss[i]][ss[j]] == 0) {
                answer++;
                break;
            }
        }
    }
    cout << answer;
    return 0;
}