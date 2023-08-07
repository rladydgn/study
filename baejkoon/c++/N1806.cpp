#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, s;
    cin >> n >> s;

    queue<int> q;
    int sum = 0;
    int answer = 999999;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        q.push(tmp);
        sum += tmp;

        while(sum >= s) {
            if(q.size() < answer) answer = q.size();
            sum -= q.front();
            q.pop();
        }
    }

    if(answer == 999999)
        answer = 0;
    cout << answer;
    return 0;
}