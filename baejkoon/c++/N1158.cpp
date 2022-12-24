#include <iostream>
#include <string>

using namespace std;

int check[5000];

int main() {
    int n, k;
    cin >> n >> k;
    
    string answer = "<";
    int now = 0;

    for(int i=0; i<n; i++) {
        int cnt = 0;
        while(cnt<k) {
            now = (now+1)%n;
            if(now == 0)
                now = n;
            if(check[now] == 0) {
                cnt++;
            }
        }
        check[now] = 1;
        answer += to_string(now) + ", ";
    }
    answer[answer.size()-2] = '>';

    cout << answer;
}