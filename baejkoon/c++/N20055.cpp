#include <iostream>
#include <queue>

using namespace std;

int robot[200];
int health[200];
int n, k;
int cnt;
// 올리는 위치, 내리는 위치
int up, down;

void moveBelt() {
    if(up == 0) up = n*2-1;
    else up -= 1;
    
    if(down == 0) down = n*2-1;
    else down -= 1;

    robot[down] = 0;
}

void moveRobot() {
    // end는 반드시 0인상태이므로, end 전에거 부터 하나씩 옮긴다.
    for(int i=1; i<n; i++) {
        if(down - i >= 0) {
            // cout << "test1 " << down-i << endl;
            if(robot[down-i] == 1 && robot[down-i+1] == 0 && health[down-i+1] > 0) {
                robot[down-i] = 0;
                robot[down-i+1] = 1;
                health[down-i+1]--;
                if(health[down-i+1] == 0) cnt++;
            }
        }
        else {
            // cout << "test2 " << n*2-(i-down-1) << endl;
            if(robot[n*2-(i-down)] == 1 && robot[(n*2-(i-down-1))%(n*2)] == 0 && health[(n*2-(i-down-1))%(n*2)] > 0) {
                robot[n*2-(i-down)] = 0;
                robot[(n*2-(i-down-1))%(n*2)] = 1;
                health[(n*2-(i-down-1))%(n*2)]--;
                if(health[(n*2-(i-down-1))%(n*2)] == 0) cnt++;
            }
        }
        robot[down] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    down = n-1;
    for(int i=0; i<n*2; i++) cin >> health[i];

    int answer = 0;
    while(k > cnt) {
        moveBelt();
        moveRobot();
        if(robot[up] == 0 && health[up] > 0) {
            // cout << "up: " << up << endl;
            robot[up] = 1;
            health[up]--;
            if(health[up] == 0) cnt++;
        }
        answer++;
        // cout << down << endl;
        // for(int i=0; i<n*2; i++) cout << robot[i] << " ";
        // cout << endl;
        // for(int i=0; i<n*2; i++) cout << health[i] << " ";
        // cout << endl << endl;
    }
    cout << answer;
    return 0;
}