#include <iostream>
#include <string>

using namespace std;

int max_value;
int max_number;

void bfs(int idx, int cnt, int sum, int arr[], int n) {
    if(cnt == 3) {
        string s = to_string(sum);
        if(max_value <= s[s.size()-1] - '0') {
            max_value = s[s.size()-1] - '0';
            max_number = n;
        }
        return;
    }

    for(int i=idx; i<5; i++) bfs(i+1, cnt+1, sum+arr[i], arr, n);
}

int main() {
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        int arr[5];
        for(int j=0; j<5; j++) {
            cin >> arr[j];
            }
        bfs(0, 0, 0, arr, i);
    }
    cout << max_number;
    return 0;
}