///
///Problem 12.2
///By Ladomiroty
///

#include <iostream>

using namespace std;

template <class T>
class List {
private:
    struct list {
        T data;
        struct list *next;
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
        int value;
        cin >> value;
        ne = new struct list;
        ne->data = value;
        ne->next = NULL;
        head = ne;

        struct list *temp = head;
        for (int i = 2; i <= n; ++i) {
            cin >> value;
            ne = new struct list;
            ne->data = value;
            ne->next = NULL;
            temp->next = ne;
            temp = ne;
        }
    }

    void print() {
        //вывод списка на экран

        struct list *temp = head;

        cout << "[ ";
        if (temp != NULL) {
            do {
                cout << temp->data << ", ";
                temp = temp->next;
            } while (temp != NULL);
        }
        cout << "]" << endl;
    }

    void printi() {
        //вывод списка на экран

        struct list *temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void merge(List<int> list1, List<int> list2) {
        struct list *temp;
        while (list1.head != NULL && list2.head != NULL) {
            while (list1.head != NULL && list1.head->data <= list2.head->data) {
                temp = list1.head;
                list1.head = list1.head->next;
                temp->next = head;
                head = temp;
            }
            if (list1.head != NULL) {
                while (list2.head != NULL && list1.head->data >= list2.head->data) {
                    temp = list2.head;
                    list2.head = list2.head->next;
                    temp->next = head;
                    head = temp;
                }
            }
        }
        if (list1.head != NULL) {
            while (list1.head != NULL) {
                temp = list1.head;
                list1.head = list1.head->next;
                temp->next = head;
                head = temp;
            }
        }
        if (list2.head != NULL) {
            while (list2.head != NULL) {
                temp = list2.head;
                list2.head = list2.head->next;
                temp->next = head;
                head = temp;
            }
        }
    }
};


int main() {
    int n, m;
    cin >> n >> m;

    List<int> list1 = List<int>();
    list1.insert(n);

    List<int> list2 = List<int>();
    list2.insert(m);

    List<int> list = List<int>();
    list.merge(list1, list2);
    list.printi();
    return 0;
}
