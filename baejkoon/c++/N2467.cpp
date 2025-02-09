#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int start = 0;
    int end = n-1;

    long long int gap = 1111111111111;
    int answer[2];
    while(start < end) {
        if(abs(arr[start]+arr[end]) < gap) {
            answer[0] = arr[start];
            answer[1] = arr[end];
            gap = abs(arr[start]+arr[end]);
        }
        if(gap == 0)
            break;
        
        if(abs(arr[start]) < arr[end])
            end--;
        else
            start++;
    }
    cout << answer[0] << " " << answer[1];
    return 0;
}