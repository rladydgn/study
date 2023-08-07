#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(const pair<int, string>& a, const pair<int, string>& b) {
    if(a.first<b.first)
        return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    pair<int, string> arr[n];
    for(int i=0; i<n; i++) {
        int a;
        string b;
        cin >> a >> b;
        arr[i] = {a, b};
    }
    stable_sort(arr, arr+n, cmp);
    for(int i=0; i<n; i++)
        cout << arr[i].first << " " << arr[i].second << "\n";
    return 0;
}