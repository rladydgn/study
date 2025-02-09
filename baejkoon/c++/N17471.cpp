#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int edges[11][11];
int population[11];
int visited[11];
int n;
int answer = 9999999;

// 집합의 연결 여부 확인
bool Bfs(vector<int>& a) {
    int check[11] = {0, };
    int check2[11] = {0, };
    for(int i=0; i<a.size(); i++)
        check[a[i]] = 1;
    
    queue<int> q;
    q.push(a[0]);
    check2[a[0]] = 1;
    while(!q.empty()) {
        int k = q.front();
        q.pop();
        for(int i=1; i<=n; i++) {
            if(edges[k][i] == 1 && check[i] == 1 && check2[i] == 0) {
                check2[i] = 1;
                q.push(i);
            }
        }
    }
    for(int i=1; i<=n; i++) {
        if(check[i] != check2[i])
            return false;
    }
    return true;
}

// 두 집합이 각각 잘 연결되어 있으면 최소차 구함
void Check(vector<int>& a, vector<int>& b) {
    if(Bfs(a) && Bfs(b)) {
        int aSum = 0;
        int bSum = 0;
        for(int i=0; i<a.size(); i++)
            aSum += population[a[i]];
        for(int i=0; i<b.size(); i++)
            bSum += population[b[i]];
        int gap = abs(aSum - bSum);
        if(gap < answer) {
            answer = gap;
        }
    }
}

// 노드를 두 집합으로 나눔
void Dfs(int now, int num, vector<int>& v) {
    if(v.size() == num) {
        vector<int> b;
        for(int i=1; i<=n; i++) {
            if(visited[i] == 0)
                b.push_back(i);
        }
        Check(v, b);
    }
    for(int i=now; i<=n; i++) {
        if(visited[i] == 0) {
            visited[i] = 1;
            v.push_back(i);
            Dfs(i+1, num, v);
            v.pop_back();
            visited[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> population[i];
    
    for(int i=1; i<=n; i++) {
        int tmp;
        cin >> tmp;
        for(int j=0; j<tmp; j++) {
            int c;
            cin >> c;
            edges[i][c] = 1;
        }
    }

    // 노드개수
    for(int i=1; i<=n/2; i++) {
        vector<int> a;
        Dfs(1, i, a);
    }

    if(answer == 9999999)
        answer = -1;
    cout << answer;

    return 0;
}