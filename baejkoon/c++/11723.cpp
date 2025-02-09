#include <iostream>
#include <string>

using namespace std;

bool arr[21];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        string cmd;
        cin >> cmd;
        if(!cmd.compare("all")) {
            for(int j=1; j<=20; j++)
                arr[j] = 1;
            continue;
        }
        else if(!cmd.compare("empty")) {
            for(int j=1; j<=20; j++)
                arr[j] = 0;
            continue;
        }

        int tmp;
        cin >> tmp;

        if(!cmd.compare("add")) {
            arr[tmp] = 1;
        }
        else if(!cmd.compare("check")) {
            cout << arr[tmp] << "\n";
        }
        else if(!cmd.compare("remove")) {
            arr[tmp] = 0;
        }
        else if(!cmd.compare("toggle")) {
            arr[tmp] = !arr[tmp];
        }
    }
    return 0;
}