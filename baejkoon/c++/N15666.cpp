#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int arr[8];
int n, m;

void dfs(int idx, int cnt, string s) {
    if(cnt == m) {
        cout << s << "\n";
        return;
    }

    for(int i=idx; i<n; i++) {
        if(i>0 && arr[i] == arr[i-1]) continue;
        dfs(i, cnt+1, s+to_string(arr[i])+" ");
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) 
        cin >> arr[i];
    sort(arr, arr+n);
    dfs(0, 0, "");
}