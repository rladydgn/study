#include <iostream>
#include <vector>

using namespace std;

int answer, n;
int arr[1001];

int main() {
    cin >> n;
    int cnt = 0;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        if(a%2 == 0) {
            answer += a;
        }
        else {
            arr[a] += 1;
            cnt++;
        }
    }
    cnt = cnt - cnt%2;
    for(int i=1000; i>0; i--) {
        if(cnt == 0) break;
        while(i%2==1 && arr[i] > 0 && cnt > 0) {
            answer += i;
            cnt--;
            arr[i]--;
        }
    }
    cout << answer;
}