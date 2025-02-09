#include <iostream>

using namespace std;

int arr[10];
int visit[10];

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for(int i=0; i<n; i++) {
        int left = arr[i];
        while(true) {
            if(visit[left]) {
                left++;
            }
            else {
                visit[left] = i+1;
                break;
            }
        }
    }
    for(int i=0; i<n; i++) {
        cout << visit[i] << " ";
    }
    return 0;
}