#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int k;
    cin >> k;
    int ar1[k], ar2[k];
    for(int i=0; i<k; i++)
        cin >> ar1[i];
    sort(ar1, ar1+k);
    for(int i=0; i<k; i++)
        cin >> ar2[i];
    sort(ar2, ar2+k);

    int sum = 0;
    for(int i=0; i<k; i++)
        sum += ar1[i] * ar2[k-1-i];
    cout << sum;
    return 0;
}
