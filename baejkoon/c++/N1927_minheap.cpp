#include <iostream>

using namespace std;

int arr[100001];
int idx = 0;

void HeapSort() {
    int s = idx;
    while(s > 1 && arr[s] < arr[s/2]) {
        swap(arr[s], arr[s/2]);
        s /= 2;
    }
}

int HeapPop() {
    int ret = arr[1];

    arr[1] = arr[idx--];

    int now = 1;
    // �ڽĳ�尡 �����ϴ� ��� ��
    while(now*2<=idx) {
        // �ڽĳ�尡 �ϳ��� �����ϴ� ���
        if(now*2+1>idx) {
            if(arr[now]>arr[now*2])
                swap(arr[now], arr[now*2]);
            break;
        }
        // �ڽĳ�尡 �ΰ� �����ϴ� ���
        else {
            // �� ���� �ڽĳ�� ����
            int min_idx;
            if(arr[now*2]<=arr[now*2+1])
                min_idx = now*2;
            else
                min_idx = now*2+1;
            
            // ���� ���� �� ���� �ڽ� ��� ��
            if(arr[min_idx] < arr[now]) {
                swap(arr[min_idx], arr[now]);
                now = min_idx;
            }
            else {
                break;
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        if(tmp == 0 && idx == 0) {
            cout << 0 << "\n";
        }
        else if(tmp == 0) {
            cout << HeapPop() << "\n";
        }
        else {
            arr[++idx] = tmp;
            HeapSort();
        }
    }
    return 0;
}