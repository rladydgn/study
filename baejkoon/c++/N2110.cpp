#include <iostream>
#include <algorithm>

using namespace std;

void Work(int lowc, int highc) {

}

int main() {
    int n, c;
    cin >> n >> c;

    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    c -= 2;
    int answer = arr[n-1] - arr[0];
    int lidx = 1, hidx = n-1;
}