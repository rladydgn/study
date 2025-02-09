#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    unordered_map<int, int> ma, mb;

    for(int i=0; i<a; i++) {
        int tmp;
        cin >> tmp;
        ma[tmp] = 1;
    }
    for(int i=0; i<b; i++) {
        int tmp;
        cin >> tmp;
        mb[tmp] = 1;
    }

    int answer = 0;
    for(auto iter=ma.begin(); iter != ma.end(); iter++) {
        if(!mb[iter->first])
            answer++;
    }
    for(auto iter=mb.begin(); iter != mb.end(); iter++) {
        if(!ma[iter->first])
            answer++;
    }
    cout << answer;

    return 0;
}