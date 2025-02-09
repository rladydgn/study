#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int arr[26];

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<s.size(); j++) {
            arr[s[j]-'A'] += pow(10, s.size() - j - 1);
        }
    }
    sort(arr, arr+26);

    int answer = 0;
    int cnt = 9;
    for(int i=25; i>=0; i--) {
        if(arr[i] == 0) break;
        answer += arr[i] * cnt--;
    }
    cout << answer;
    return 0;
}