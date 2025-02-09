#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    while(n--) {
        int a;
        cin >> a;
        int arr[a];
        for(int i=0; i<a; i++) {
            cin >> arr[i];
        }

        long long int answer = 0;
        long long profit = 0;
        int now = arr[a-1];
        for(int i=a-2; i>=0; i--) {
            if(arr[i] >= now) {
                answer += profit;
                profit = 0;
                now = arr[i];
            }
            else {
                profit += now - arr[i];
            }
        }
        answer += profit;

        cout << answer << "\n";
    }
    return 0;
}