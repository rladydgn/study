#include <iostream>

using namespace std;

int n, k;
int answer;
int arr[8];
int visited[8];

void Dfs(int day, int weight) {
    if(day == n) {
        answer++;
        return;
    }
    weight -= k;
    for(int i=0; i<n; i++) {
        if(arr[i]+weight>=500 && visited[i] == 0) {
            visited[i] = 1;
            Dfs(day+1, weight+arr[i]);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    Dfs(0, 500);

    cout << answer;

    return 0;
}