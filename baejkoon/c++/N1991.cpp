#include <iostream>
using namespace std;

char tree[27];

void preorder(int idx) {
	if(idx > 26 || tree[idx] == '.')
		return;
	cout << tree[idx];
	preorder(idx*2);
	preorder(idx*2+1);
}

void inorder(int idx) {
	if(idx > 26 || tree[idx] == '.')
		return;
	inorder(idx*2);
	cout << tree[idx];
	inorder(idx*2+1);
}

void postorder(int idx) {
	if(idx > 26 || tree[idx] == '.')
		return;
	postorder(idx*2);
	postorder(idx*2+1);
	cout << tree[idx];
}

int main() {
	int n;
	cin >> n;
	int idx = 1;
	tree[1] = 'A';
	for(int i=0; i<n; i++) {
		char root, left, right;
		cin >> root >> left >> right;
		for(int j=1; j<27; j++) {
			if(tree[j] == root) {
				idx = j;
				break;
			}
		}
		
		tree[idx*2] = left;
		tree[idx*2+1] = right;
	}
	preorder(1);
	cout << "\n";
	inorder(1);
	cout << "\n";
	postorder(1);
}
