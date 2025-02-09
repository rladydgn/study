#include <iostream>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;

    int answer = 0;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        a = a - (n - i);
        if(a<0) a = 0;
        answer = max(a, answer);
    }
    cout << answer;
    return 0;
}