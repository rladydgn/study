#include <iostream>
#include <cmath>

using namespace std;

int arr[4000001];

void prime(const int& n) {
    for(int i=2; i<=sqrt(n); i++) {
        int idx = 2;
        while(i*idx<=n) {
            arr[i*idx] = 1;
            idx++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    prime(n);
    
    int start = 2, end = 2;
    int sum = 0;
    int answer = 0;
    while(end <= n) {
        if(arr[end] == 0) sum += end;
        end++;
        
        if(sum > n) {
            while(sum > n) {
                sum -= start;
                start++;
                while(arr[start] != 0) start++;
            }
        }

        if(sum == n) {
            answer++;
            sum -= start;
            start++;
            while(arr[start] != 0) start++;
        }
    }
    cout << answer;
    return 0;
}