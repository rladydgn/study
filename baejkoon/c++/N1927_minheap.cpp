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
    // 자식노드가 존재하는 경우 비교
    while(now*2<=idx) {
        // 자식노드가 하나만 존재하는 경우
        if(now*2+1>idx) {
            if(arr[now]>arr[now*2])
                swap(arr[now], arr[now*2]);
            break;
        }
        // 자식노드가 두개 존재하는 경우
        else {
            // 더 작은 자식노드 선출
            int min_idx;
            if(arr[now*2]<=arr[now*2+1])
                min_idx = now*2;
            else
                min_idx = now*2+1;
            
            // 현재 노드와 더 작은 자식 노드 비교
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