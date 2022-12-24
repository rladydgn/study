#include <iostream>
#include <string>

using namespace std;

int n;
int arr[13];

void Dfs(int idx, int cnt, string s) {
    if(cnt == 6) {
        cout << s << "\n";
        return;
    }
    // cout << arr[idx] << " " << cnt << endl;
    for(int i=idx; i<n; i++) {
        Dfs(i+1, cnt+1, s + to_string(arr[i]) + " ");
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(true) {
        cin >> n;
        if(n == 0)
            break;
        
        for(int i=0; i<n; i++)
            cin >> arr[i];
        Dfs(0, 0, "");
        cout << "\n";
    }
}