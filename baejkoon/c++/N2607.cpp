#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int arr1[26], arr2[26];

int main() {
    int n;
    cin >> n;
    int answer = 0;
    string tmp;
    cin >> tmp;
    for(int i=0; i<tmp.size(); i++) {
        arr1[tmp[i]-'A'] += 1;
    }

    for(int i=1; i<n; i++) {
        cin >> tmp;
        for(int j=0; j<tmp.size(); j++) {
            arr2[tmp[j]-'A'] += 1;
        }

        int sum1 = 0, sum2 = 0;
        for(int j=0; j<26; j++) {
            sum1 = sum1 + abs(arr1[j] - arr2[j]);
            sum2 = sum2 + arr1[j] - arr2[j];
            arr2[j] = 0;
        }
        if(sum1 <= 2 && sum2>=-1 && sum2<=1) answer++;
    }
    cout << answer;
    return 0;
}