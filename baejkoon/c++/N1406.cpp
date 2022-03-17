#include <iostream>
using namespace std;

struct Node {
    char c;
    Node before;
    Node after;
};

int main() {
    char *st = new char[100000];
    cin >> st;
    int n;
    cin >> n;
    Node curse;
    curse.c = st[0];
    for(int i=1; i<100000; i++) {
        if(st[i] == NULL)
            break;
        Node tmp;
        tmp.c = st[i];
        tmp.before = &curse;
        curse.after = &tmp;
        curse = tmp;
    }
    cout << st;
}
