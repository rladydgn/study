#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n];
    int start = 0;
    int sum = 0;
    int answer = 0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        sum += arr[i];
        while(start<i && sum > m) {
            sum -= arr[start++];
        }
        if(sum == m) answer++;
    }
    cout << answer;
    return 0;
}