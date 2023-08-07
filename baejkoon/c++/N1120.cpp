#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int gap = b.size() - a.size();

    int idx = 0;
    int answer = 9999;
    for(int i=0; i<=gap; i++) {
        int cnt = 0;
        for(int j=0; j<a.size(); j++) {
            if(a[j] != b[j+i]) cnt++;
        }
        if(cnt<answer) answer = cnt;
    }
    cout << answer;

    return 0;
}