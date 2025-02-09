#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int m = 999999;
        int answer = 0;
        for(int j=0; j<7; j++) {
            int t;
            cin >> t;
            if(t%2==0) {
                answer += t;
                if(m>t)
                    m = t;
            }
        }
        cout << answer << " " << m << "\n";
    }
    return 0;
}