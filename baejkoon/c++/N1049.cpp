#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[m], b[m];
    for(int i=0; i<m; i++)
        cin >> a[i] >> b[i];

    sort(a, a+m);
    sort(b, b+m);

    int answer = 0;
    if(a[0] >= b[0]*6) {
        cout << n*b[0];
        return 0;
    }

    answer = (n/6) * a[0];
    n = n%6;
    if(a[0] >= n*b[0])
        answer = answer + n*b[0];
    else
        answer = answer + a[0];
    
    cout << answer;

    return 0;
}