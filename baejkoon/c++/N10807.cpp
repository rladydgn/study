#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int k;
    cin >> k;
    int answer = 0;
    for(int i=0; i<n; i++)
        if(k == arr[i]) answer++;
    
    cout << answer;

    return 0;
}