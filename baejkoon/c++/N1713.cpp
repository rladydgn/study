#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if(a.second < b.second)
        return true;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    // ��õ��, �л���ȣ
    vector<pair<int, int>> v;
    for(int i=0; i<m; i++) {
        int c;
        cin >> c;
        bool check = true;
        // vector�� ���� �̹� �� �ִ� ��츦 ã��
        for(int j=0; j<v.size(); j++) {
            if(v[j].second == c) {
                v[j].first++;
                check = false;
                break;
            }
        }

        // vector�� ���� �� ���� ���� ���
        if(check) {
            // ��ϵ� �׸��� ���� vector�� ����� �������
            if(v.size() < n) {
                v.push_back({1, c});
            }
            // ��ϵ� �׸��� ���� vector�� ����� ũ�ų� �������
            else {
                int mini = 9999999;
                int idx = 9999;
                // ���� ��õ���� ���� �ʰ� ���� �л��� ã�´�.
                for(int j=0; j<v.size(); j++) {
                    if(v[j].first < mini) {
                        mini = v[j].first;
                        idx = j;
                    }
                }
                v.erase(v.begin() + idx);
                v.push_back({1, c});
            }
        }
    }

    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<v.size(); i++)
        cout << v[i].second << " ";

    return 0;
}