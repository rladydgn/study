#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr, arr+n);
    
    int answer = 1;
    int start = arr[0];
    for(int i=1; i<n; i++) {
        if(l- (arr[i] - start) >= 1) continue;
        start = arr[i];
        answer++;
    }

    cout << answer;

    return 0;
}