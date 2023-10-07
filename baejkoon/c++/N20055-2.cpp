#include <iostream>
#include <queue>

using namespace std;

int robot[200];
int health[200];
int n, k;
int cnt;

void moveBelt() {
    int save_robot = robot[2*n-1];
    int save_health = health[2*n-1];
    for(int i=2*n-1; i>0; i--) {
        robot[i] = robot[i-1];
        health[i] = health[i-1];
    }
    robot[0] = save_robot;
    health[0] = save_health;

    robot[n-1] = 0;
}

void moveRobot() {
    for(int i=n-2; i>=0; i--) {
        if(robot[i] == 1 && health[i+1] > 0 && robot[i+1] == 0) {
            robot[i] = 0;
            robot[i+1] = 1;
            health[i+1]--;
            if(health[i+1] == 0) cnt++;
        }
    }
    robot[n-1] = 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for(int i=0; i<n*2; i++) cin >> health[i];

    int answer = 0;
    while(k > cnt) {
        moveBelt();
        moveRobot();
        if(robot[0] == 0 && health[0] > 0) {
            // cout << "up: " << up << endl;
            robot[0] = 1;
            health[0]--;
            if(health[0] == 0) cnt++;
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