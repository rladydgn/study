#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ar1[n], ar2[n];
    for(int i=0; i<n; i++)
        cin >> ar1[i];
    sort(ar1, ar1+n);
    for(int i=0; i<n; i++)
        cin >> ar2[i];
    sort(ar2, ar2+n);

    int sum = 0;
    for(int i=0; i<n; i++)
        sum += ar1[i] * ar2[n-1-i];
    cout << sum;
    return 0;
}
