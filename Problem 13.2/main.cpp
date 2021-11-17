///
///Problem 13.1
///By Ladomitory
///

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class tree {
private:
    struct node {
        int value;
        struct node *right;
        struct node *left;
    };

    struct node *root;
public:
    tree() {
        root = new struct node;
        root->right = NULL;
        root->left = NULL;
        root = NULL;
    }

    bool empty() {
        return (root == NULL);
    }

    void insert(int value) {
        struct node *New = new struct node;
        New->value = value;
        New->left = NULL;
        New->right = NULL;
        if (empty()) {
            root = New;
            return;
        }
        struct node *temp = root;
        while (true) {
            if (temp->value > value) {
                if (temp->left == NULL) {
                    temp->left = New;
                    break;
                } else {
                    temp = temp->left;
                }
            } else if (temp->value < value) {
                if (temp->right == NULL) {
                    temp->right = New;
                    break;
                } else {
                    temp = temp->right;
                }
            } else {
                break;
            }
        }
    }

    void prefixPrint(struct node *temp) {
        if (temp == NULL) {
            return;
        }
        cout << temp->value << ' ';
        prefixPrint(temp->left);
        prefixPrint(temp->right);
    }

    void infixPrint(struct node *temp) {
        if (temp == NULL) {
            return;
        }
        infixPrint(temp->left);
        cout << temp->value << endl;
        infixPrint(temp->right);
    }

    void postfixPrint(struct node *temp) {
        if (temp == NULL) {
            return;
        }
        postfixPrint(temp->left);
        postfixPrint(temp->right);
        cout << temp->value << ' ';
    }

    void Print() {
        prefixPrint(root);
        cout << endl;
        postfixPrint(root);
        cout << endl;
    }

    void makenull() {

    }
};

int main() {
    ifstream fin("input.txt");

    int n;
    tree t;

    while (fin >> n) {
        t.insert(n);
    }

    t.Print();

    return 0;
}