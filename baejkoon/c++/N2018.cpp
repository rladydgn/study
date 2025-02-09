#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 1;
    int high = 1, low = 1;
    int answer = 1;
    while(high < n) {
        if(sum == n) {
            answer++;
            high++;
            sum += high;
        }
        else if(sum < n) {
            high++;
            sum += high;
        }
        else {
            sum -= low++;
        }
    }
    cout << answer;

    return 0;
}