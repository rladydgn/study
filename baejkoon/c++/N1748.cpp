#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    int answer = 0;
    int cnt = 1;
    int k = n;
    while(k!=0) {
        if(k/10==0) {
            answer = answer + (n-pow(10, cnt-1) + 1) * cnt;
        }
        else {
            answer = answer + (pow(10, cnt)-pow(10, cnt-1))*cnt;
            cnt++;
        }
        k /= 10;
    }
    cout << answer;
    return 0;
}