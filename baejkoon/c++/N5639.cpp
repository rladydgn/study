#include <iostream>

using namespace std;

struct node {
    int value;
    node* left;
    node* right;
};

node* root;

void Insert(int n) {
    node* vertex = new node();
    vertex->value = n;

    if(root == nullptr) {
        root = vertex;
    }
    else {
        node* now = root;
        while(true) {
            if(now->value > vertex->value) {
                if(now->left == nullptr) {
                    now->left = vertex;
                    return;
                }
                now = now->left;
            }
            else {
                if(now->right == nullptr) {
                    now->right = vertex;
                    return;
                }
                now = now->right;
            }
        }
    }

}

void Postfix(node* now) {
    if(now->left != nullptr) {
        Postfix(now->left);
    }
    if(now->right != nullptr) {
        Postfix(now->right);
    }
    cout << now->value << "\n";
}

int main() {
    while(true) {
        int n;
        cin >> n;
        if(cin.eof())
            break;
        Insert(n);
        // cout << root->value << endl;
    }
    Postfix(root);
}