#include <iostream>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    int arr[w];
    for(int i=0; i<w; i++)
        cin >> arr[i];

    int answer = 0;
    for(int i=h; i>0; i--) {
        int start = -1;
        for(int j=0; j<w; j++) {
            if(arr[j] >= i && start == -1) {
                start = j;
            }
            else if(arr[j] >= i) {
                answer = answer + j - (start+1);
                start = j;
            }
        }
    }

    cout << answer;

    return 0;
}