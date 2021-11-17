///
///Problem 13.3
///By Ladomitory
///

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class tree {
private:
    struct node {
        char value;
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

    void insert(char value) {
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
            if ('0' <= value && value <= '9') {
                if (temp->left == NULL) {

                }
            }
            break;
        }

    }
};

int main() {
    return 0;
}