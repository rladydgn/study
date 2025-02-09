#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int visited[6][6];

int main() {
    string before;
    cin >> before;
    visited[before[0]-'A'][before[1]-'1'] = 1;
    string start = before;
    for(int i=1; i<36; i++) {
        string s;
        cin >> s;
        int a = abs(before[0] - s[0]);
        int b = abs(before[1] - s[1]);
        // �ùٸ� ��ġ�� �̵��ߴ���, �ߺ��̵��� ������ Ȯ��
        if(!((a == 1 && b == 2) || (a == 2 && b == 1)) || visited[s[0]-'A'][s[1]-'1']) {
            cout << "Invalid";
            return 0;
        }
        visited[s[0]-'A'][s[1]-'1'] = 1;
        before = s;
    }
    // ó�� ��ġ�� �̵��������� Ȯ��
    int a = abs(start[0] - before[0]);
    int b = abs(start[1] - before[1]);
    if(!((a == 1 && b == 2) || (a == 2 && b == 1))) {
        cout << "Invalid";
        return 0;
    }
    cout << "Valid";
    return 0;
}