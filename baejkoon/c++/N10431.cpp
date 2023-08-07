#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int number;
        cin >> number;
        int answer = 0;
        int arr[20];
        cin >> arr[0];
        for(int j=1; j<20; j++) {
            cin >> arr[j];
            for(int k=0; k<j; k++) {
                if(arr[k]>arr[j]) {
                    int tmp = arr[k];
                    arr[k] = arr[j];
                    for(int l=k; l<j; l++) {
                        swap(tmp, arr[l+1]);
                        answer++;
                    }
                    break;
                }
            }
        }
        cout << number << " " << answer << "\n";
    }
    return 0;
}