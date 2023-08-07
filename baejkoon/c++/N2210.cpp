#include <iostream>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

int main() {
    string arr[5][5];
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            cin >> arr[i][j];

    unordered_set<string> v;
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            queue<pair<string, pair<int, int>>> q;
            q.push({"", {i, j}});
            while(!q.empty()) {
                string str = q.front().first;
                pair<int, int> cor = q.front().second;
                q.pop();

                if(str.length() == 6) {
                    v.insert(str);
                    continue;
                }

                int y[] = {0, 0, 1, -1};
                int x[] = {1, -1, 0, 0};
                for(int k=0; k<4; k++) {
                    int dy = cor.first + y[k];
                    int dx = cor.second + x[k];

                    if(dy>=0 && dy<5 && dx>=0 && dx<5) {
                        q.push({str+arr[dy][dx], {dy, dx}});
                    }
                }
            }
        }
    }
    cout << v.size();
    return 0;
}