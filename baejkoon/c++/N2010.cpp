#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int answer = 0;
    int t;
    for(int i=0; i<n-1; i++) {
        cin >> t;
        answer += t-1;
    }
    cin >> t;
    answer += t;

    cout << answer;

    return 0;
}