#include <iostream>

using namespace std;

int m[200001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    int answer = 0;

    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        if(m[a] == 0) {
            if(b == 1)
                m[a] = 1;
            else
                answer += 1;
        }
        else {
            if(b == 1)
                answer += 1;
            else
                m[a] = 0;
        }
    }

    for(auto iter=1; iter<200001; iter++) {
        answer += m[iter];
    }

    cout << answer;

    return 0;
}