#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int getSum(string a) {
    int s = 0;
    for(int i=0; i<a.size(); i++) {
        if(a[i] >= '0' && a[i] <= '9') {
            s += a[i] - '0';
        }
    }
    return s;
}

bool cmp(string a, string b) {
    if(a.size() < b.size())
        return true;
    if(a.size() == b.size() && getSum(a) < getSum(b))
        return true;
    if(a.size() == b.size() && getSum(a) == getSum(b) && a<b)
        return true;
    return false;
}
int main() {
    int n;
    cin >> n;
    string arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n, cmp);
    for(int i=0; i<n; i++) {
        cout << arr[i] << "\n";
    }

    return 0;
}