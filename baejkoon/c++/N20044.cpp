#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n*2];
    for(int i=0; i<n*2; i++)
        cin >> arr[i];

    sort(arr, arr+n*2);
    int answer = 999999999;
    for(int i=0; i<n; i++) {
        if(arr[i]+arr[n*2-1-i] < answer) {
            answer = arr[i]+arr[n*2-1-i];
        }
    }
    cout << answer;
    return 0;
}