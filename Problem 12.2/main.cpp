//
//Problem 12.2
//By Ladomiroty
//

#include <iostream>

using namespace std;

template <class T>
class List {
private:
    struct list {
        T data;
        struct list *next;
        struct list *prev;
    };
public:
    struct list *head;
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

    void insert(int n) {
        struct list *ne;
        ne = new struct list;
        ne->data = 1;
        ne->next = NULL;
        ne->prev = NULL;
        head = ne;

        struct list *temp = head;
        for (int i = 2; i <= n; ++i) {
            ne = new struct list;
            ne->data = i;
            ne->next = NULL;
            ne->prev = temp;
            temp->next = ne;
            temp = ne;
        }
        temp->next = head;
        head->prev = temp;
    }
    void delete3(int k) {
        struct list *ctemp = head, *temp;
        while (ctemp != ctemp->next) {
            for (int i = 0; i < k - 1; ++i) {
                ctemp = ctemp->next;
            }

            if (ctemp == head) {
                ctemp->prev->next = ctemp->next;
                head = ctemp->next;
                ctemp->next->prev = ctemp->prev;
                temp = ctemp->next;
                free(ctemp);
                ctemp = temp;
            } else {
                ctemp->prev->next = ctemp->next;
                ctemp->next->prev = ctemp->prev;
                temp = ctemp->next;
                free(ctemp);
                ctemp = temp;
            }
        }
    }

    void print() {
        //вывод списка на экран

        struct list *temp = head;

        cout << "[ ";
        do {
            cout << temp->data << ", ";
            temp = temp->next;
        } while (temp != head);
        cout << "]\n";
    }
};


int main() {
    int n, k;
    cin >> n >> k;
    List<int> l;
    l.insert(n);
    l.delete3(k);
    cout << l.head->data << endl;
    return 0;
}
