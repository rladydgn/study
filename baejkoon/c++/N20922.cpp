#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> um;
    int start = 0, end = 0;
    int answer = 0;
    int arr[n];
    while(end < n) {
        cin >> arr[end];
        um[arr[end]]++;
        if(um[arr[end]] > k) {
            while(um[arr[end]] > k) {
                um[arr[start++]]--;
            }
        }
        end++;
        answer = max(answer, end-start);
    }
    cout << answer;
    return 0;
}