#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, x;
    cin >> n >> x;

    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int value = 0;
    for(int i=0; i<x; i++)
        value += arr[i];

    int answer = value;
    int cnt = 1;
    for(int i=x; i<n; i++) {
        value = value + arr[i] - arr[i-x];
        if(answer < value) {
            answer = value;
            cnt = 1;
        }
        else if(answer == value)
            cnt++;
    }

    if(answer == 0)
        cout << "SAD";
    else
        cout << answer << "\n" << cnt;

    return 0;
}