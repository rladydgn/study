#include <iostream>

using namespace std;

int arr[1001];

int main() {
    int answer = 0;
    for(int i=0; i<10; i++) {
        int n;
        cin >> n;
        if(arr[n%42] == 0) {
            arr[n%42] = 1;
            answer++;
        }
    }
    cout << answer;

    return 0;
}