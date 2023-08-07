#include <iostream>

using namespace std;

int kayak[12];

int main() {
    int n, s, r;
    cin >> n >> s >> r;

    for(int i=1; i<=n; i++) {
        kayak[i]++;
    }

    int answer = 0;
    for(int i=0; i<s; i++) {
        int a;
        cin >> a;
        kayak[a]--;
    }

    for(int i=0; i<r; i++) {
        int a;
        cin >> a;
        kayak[a]++;
    }

    for(int i=1; i<=n; i++) {
        if(kayak[i] == 2) {
            if(kayak[i-1] == 0) {
                kayak[i-1]++;
            }
            else if(kayak[i+1] == 0) {
                kayak[i+1]++;
            }
        }
    }

    for(int i=1; i<=n; i++) {
        if(kayak[i] == 0) answer++;
    }
    cout << answer;
    return 0;
}