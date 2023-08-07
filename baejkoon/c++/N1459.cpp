#include <iostream>

using namespace std;

int main() {
    long long int x, y, w, s;
    cin >> x >> y >> w >> s;

    if(w*2 <= s) {
        cout << (x+y)*w;
        return 0;
    }

    long long int answer = 0;
    if(x<=y) {
        answer = x*s;
        answer = answer+(y-x)*w;
    }
    else {
        answer = y*s;
        answer = answer+(x-y)*w;
    }

    if((x+y)%2==0) {
        answer = min(answer, max(x, y)*s);
    }
    else {
        answer = min(answer, max(x, y)*s+w-s);
    }

    cout << answer;

    return 0;
}