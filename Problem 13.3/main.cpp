///
///Problem 13.3
///By Ladomitory
///

#include <iostream>
#include <string>

using namespace std;

class tree {
private:
    struct node {
        char symb;
        struct node *right;
        struct node *left;
    };

    string line;

    struct node* insertHelper();

    bool delNull = false;

public:
    struct node *root;

    tree();
    bool empty();
    void insert(string line);
    int compulate(struct node *temp);
    bool checkError();
};

tree::tree() {
    root = new struct node;
    root = NULL;
}

bool tree::empty() {
    return (root == NULL);
}

void tree::insert(string line) {
    this->line = line;
    root = insertHelper();
}

tree::node* tree::insertHelper() {
    int ind = 0;
    struct node *temp;
    temp = new struct node;
    temp->symb = line[ind];
    temp->left = NULL;
    temp->right = NULL;

    line.erase(ind, 1);
    if (temp->symb < '0' || temp->symb > '9') {
        temp->left = insertHelper();
        temp->right = insertHelper();
    }
    return temp;
}

int tree::compulate(struct node *temp) {
    if ('0' <= temp->symb && temp->symb <= '9') {
        return (temp->symb - '0');
    } else {
        int a = compulate(temp->left);
        int b = compulate(temp->right);
        if (temp->symb == '+') {
            return a + b;
        } else if (temp->symb == '-') {
            return a - b;
        } else if (temp->symb == '*') {
            return a * b;
        } else if (temp->symb == '/') {
            if (b == 0) {
                delNull = true;
                return 0;
            }
            return a / b;
        }
    }
    return 0;
}

bool tree::checkError() {
    return delNull;
}

int main(){
    tree t = tree();
    string line;
    getline(cin, line);
    t.insert(line);
    int ans = t.compulate(t.root);
    if (t.checkError()) {
        cout << "NO" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}