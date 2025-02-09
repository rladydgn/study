#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr, arr+n);

    long long int answer = 0;
    int rank = 1;
    for(int i=0; i<n; i++) {
        answer = answer + abs(arr[i]-rank++);
    }

    cout << answer;

    return 0;
}