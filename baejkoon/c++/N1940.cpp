#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    sort(arr, arr+n);
    int start = 0, end = n-1;
    int answer = 0;
    while(start<end) {
        int tmp = arr[start] + arr[end];
        if(tmp>m) {
            end--;
        }
        else if(tmp<m) {
            start++;
        }
        else {
            answer++;
            start++;
            end--;
        }
    }
    cout << answer;
    return 0;
}