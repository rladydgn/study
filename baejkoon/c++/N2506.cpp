#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int answer = 0;
    int cnt = 1;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        if(a == 1) answer += cnt++;
        else cnt = 1;
    }

    cout << answer;

    return 0;
}