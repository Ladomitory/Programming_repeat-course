///
///Problem 13.3
///By Ladomitory
///

#include <iostream>

using namespace std;

class tree {
private:
    struct node {
        char symb;
        struct node *right;
        struct node *left;
    };

    string line;

    void insertHelper(struct node *temp);

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
    insertHelper(root);
}

void tree::insertHelper(struct node *temp) {
    int ind = 0;
    struct node *New;
    New = new struct node;
    New->symb = line[ind];
    New->left = NULL;
    New->right = NULL;

    temp = New;
    if (root == NULL) {
        root = temp;
    }
    line.erase(ind, 1);
    if (temp->symb < '0' || temp->symb > '9') {
        insertHelper(temp->left);
        insertHelper(temp->right);
    }
}

int tree::compulate(struct node *temp) {
    cout << temp->symb << endl;
    if ('0' <= temp->symb && temp->symb <= '9') {
        return temp->symb;
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
    cout << "End insert" << endl;
    int ans = t.compulate(t.root);
    cout << "End compulate" << endl;
    if (t.checkError()) {
        cout << "NO" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}