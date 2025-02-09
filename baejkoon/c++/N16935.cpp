#include <iostream>

using namespace std;

int arr[100][100];
int n, m, r;

void First() {
    for(int i=0; i<n/2; i++) {
        for(int j=0; j<m; j++) {
            int tmp = arr[i][j];
            arr[i][j] = arr[n-1-i][j];
            arr[n-1-i][j] = tmp;
        }
    }
}

void Second() {
    for(int j=0; j<m/2; j++) {
        for(int i=0; i<n; i++) {
            int tmp = arr[i][j];
            arr[i][j] = arr[i][m-1-j];
            arr[i][m-1-j] = tmp;
        }
    }
}

void Third() {
    int tarr[100][100];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            tarr[i][j] = arr[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            arr[]
        }
    }
}


int main() {
    cin >> n >> m >> r;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<r; i++) {
        int k;
        cin >> k;
        if(k == 1) {
            First();
        }
        else if(k == 2) {
            Second();
        }
        else if(k == 3) {
            Third();
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}