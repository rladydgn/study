#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<pair<string, int>>> room;
int check[300];
int p, m;

void print() {
    for(int i=0; i<room.size(); i++) {
        sort(room[i].begin(), room[i].end());
        if(room[i].size() == m) {
            cout << "Started!\n";
        }
        else {
            cout << "Waiting!\n";
        }
        for(int j=0; j<room[i].size(); j++) {
            cout << room[i][j].second << " " << room[i][j].first << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> p >> m;

    for(int i=0; i<p; i++) {
        int a;
        string s;
        cin >> a >> s;
        bool tf = true;
        for(int j=0; j<room.size(); j++) {
            if(room[j][0].second-10 <= a && room[j][0].second+10 >= a && room[j].size() < m) {
                room[j].push_back({s, a});
                tf = !tf;
                break;
            }
        }
        if(tf) {
            room.push_back({{s, a}});
        }
    }
    print();
    return 0;
}