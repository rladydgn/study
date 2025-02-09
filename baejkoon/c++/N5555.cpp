#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int n;
    cin >> s >> n;
    int answer = 0;
    for(int i=0; i<n; i++) {
        string tmp;
        cin >> tmp;
        tmp = tmp + tmp;
        int k = tmp.find(s);
        if(k != std::string::npos) {
            answer++;
        } 
    }
    cout << answer;

    return 0;
}