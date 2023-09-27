#include <iostream>
#include <string>

using namespace std;

void insert(int arr[], char value) {
    if(value >= 'A' && value <='Z') {
        arr[value-'A'+1]++;
    }
    else if(value >= 'a' && value <= 'z') {
        arr[value-'a'+27]++;
    }
    else {
        arr[value-' ']++;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    int arr1[53] = {0, }, arr2[53] = {0, };

    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        arr1[tmp]++;
    }

    string s;
    cin.ignore();
    getline(cin, s);
    for(int i=0; i<s.size(); i++) {
        insert(arr2, s[i]);
    }

    for(int i=0; i<53; i++) {
        if(arr1[i] != arr2[i]) {
            cout << "n";
            return 0;
        }
    }
    cout << "y";
    return 0;
}