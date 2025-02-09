#include <iostream>

using namespace std;

int main() {
    int answer[] = {0, 0};
    for (size_t i = 0; i < 9; i++)
    {
        int n;
        cin >> n;
        if(answer[0]<n) {
            answer[0] = n;
            answer[1] = i+1;
        }
    }
    cout << answer[0] << "\n" << answer[1];
    return 0;
}