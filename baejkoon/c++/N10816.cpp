#include <string>
#include <iostream>
#include <map>
using namespace std;

/** quick sort
void quickSort(int i, int j, int *ar) {
    cout << i << " " << j << "\n";
    if(i>=j)
        return;
    int pivot = ar[i];
    int start = i;
    int en = j;
    while(start < en) {
        while(ar[start]<=pivot&&start<j) {
            start++;
        }
        while(ar[en]>pivot&&en>i)
            en--;
        if(start<en) {
            int tmp = ar[start];
            ar[start] = ar[en];
            ar[en] = tmp;
        }
    }
    ar[i] = ar[en];
    ar[en] = pivot;
    quickSort(i, en-1, ar);
    quickSort(en+1, j, ar);
}
**/

int main() {
    cout.tie(0); cin.tie(0); ios_base::sync_with_stdio(false);
    int n1;
    cin >> n1;
    map<int, int> m;
    for(int i=0; i<n1; i++) {
        int tmp;
        cin >> tmp;
        m[tmp] += 1;
    }
    int n2;
    cin >> n2;
    for(int i=0; i<n2; i++) {
        int tmp;
        cin >> tmp;
        cout << m[tmp] << " ";
    }
    return 0;
}
