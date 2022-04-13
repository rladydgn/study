#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int x;
    int y;
};

bool compare(Node a, Node b) {
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int main() {
    int n;
    cin >> n;
    Node nodes[n];
    for(int i=0; i<n; i++) {
        cin >> nodes[i].x;
        cin >> nodes[i].y;
    }
    sort(nodes, nodes+n, compare);
    for(int i=0; i<n; i++)
        cout << nodes[i].x << " " << nodes[i].y << "\n";
    return 0;
}
