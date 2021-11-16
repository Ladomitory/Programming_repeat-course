//
//Problem 12.1
//By Ladomitory
//
#include <iostream>
#include <fstream>

using namespace std;

class List {
private:
    struct list {
        int data;
        struct list *next;
    };
    struct list *head;
public:
    List() {
        head = new struct list;
        head = NULL;
    }

    int size() {
        //возвращяет число элиментов.

        int ln = 0;
        struct list *temp = head;
        while (temp != NULL) {
            ln++;
            temp = temp->next;
        }
        return ln;
    }

    void insert() {
        //вставка после указанного индеском элимента.
        ifstream fin("input.txt");
        auto NE = new list();
        int value;
        fin >> value;
        NE->next = NULL;
        NE->data = value;
        head = NE;
        struct list *temp = head;
        while (fin >> value) {
            auto ne = new list();
            ne->data = value;
            ne->next = NULL;
            temp->next = ne;
            temp = temp->next;
        }
    }

    void makenull() {
        //очистка списка.

        struct list *temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }
    }

    void deleteRepeirs() {
        //удаляет повторяющиеся идущие подрят элименты.
        int ln = size();
        if (ln == 0) {
            return;
        } if (ln == 1) {
            cout << head->data;
            return;
        }

        struct list *temp, *templ = head, *tempr = head->next;
        bool count = true;
        while (tempr != NULL) {
            cout << templ->data << ' ';
            while (tempr != NULL && templ->data == tempr->data) {
                temp = tempr;
                tempr = tempr->next;
                templ->next = tempr;
                free(temp);
                count = false;
            }
            if (tempr != NULL) {
                templ = tempr;
                tempr = tempr->next;
                count = true;
            }
        }
        if (count) {
            cout << templ->data << ' ';
        }

    }


};

int main() {
    List l = List();
    l.insert();
    l.deleteRepeirs();
    return 0;
}