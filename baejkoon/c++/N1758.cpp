#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr, arr+n, greater<>());
    long long int answer = 0;
    for(int i=0; i<n; i++) {
        int a = arr[i] - i;
        if(a>0) {
            answer += a;
        }
    }
    cout << answer;
    return 0;
}