#include <iostream>
#include <string>
using namespace std;

struct node {
	char c;
	node* right;
	node* left;
};

int main() {
	node *a = new node();
	a->left = NULL;
	string s;
	cin >> s;
	for(int i=0; i<s.size(); i++) {
		node *b = new node();
		b->c = s[i];
			
		a->right = b;
		b->left = a;
		
		a = b;
	}
	a->right = NULL;
	
	int n;
	cin >> n;
	
	
	for(int i=0; i<n; i++) {
		char c;
		cin >> c;
		
		if(c == 'L' && a->left != NULL) {
			a = a->left;	
		}
		else if(c == 'D' && a->right != NULL) {
			a = a->right;
		}
		else if(c == 'B' && a->left != NULL) {
			if(a->right != NULL) {
				a->left->right = a->right;
				a->right->left = a->left;
			}
			else {
				a->left->right = NULL;
			}
			a = a->left;
		}
		else if(c == 'P'){
			char k;
			cin >> k;
			node *b = new node();
			if(a->right != NULL) {
				b->right = a->right;
				a->right->left = b;
			}
			else
				b->right = NULL;
			b->left = a;
			a->right = b;
			b->c = k;
			a = b;
		}
		//cout << a->c << endl;
	}
	
	while(a->left != NULL) {
		a = a->left;
	}
	
	while(a->right != NULL) {
		if(a->c != NULL)
			cout << a->c;
		a = a->right;
	}
	cout << a->c;
}
