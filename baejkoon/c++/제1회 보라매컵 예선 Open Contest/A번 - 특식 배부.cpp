#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];

    int answer = 0;
    for(int i=0; i<3; i++) {
        if(n>arr[i])
            answer += arr[i];
        else
            answer += n;
    }
    cout << answer;

    return 0;
}