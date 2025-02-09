#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<long long int> v;

void func(int now, string value) {
    if(value.size()>=1)
        v.push_back(stoll(value));
    for(int i=now; i<=9; i++) {
        func(i+1, to_string(i)+value);
    }
}

int main() {
    cin >> n;
    func(0, "");
    sort(v.begin(), v.end());
    if(n >= 1023)
        cout << -1;
    else
        cout << v[n];
    return 0;
}