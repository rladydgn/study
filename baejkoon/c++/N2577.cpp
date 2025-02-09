#include <iostream>

using namespace std;

int arr[11];

int main() {
    long long int a, b, c;
    long long int answer = 0;
    cin >> a >> b >> c;
    answer = a*b*c;
    string s = to_string(answer);
    for(int i=0; i<s.size(); i++) {
        arr[s[i]-'0'] += 1;
    }
    for(int i=0; i<10; i++) {
        cout << arr[i] << "\n";
    }
    return 0;
}