//
//Problem 11.2
//By Ladomitory
//

#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class List {
private:
    struct list {
        T data;
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

    void insert(T value, int ind = -1) {
        //вставка после указанного индеском элимента.

        //ind указывает после какого элемента нужно вставить, нумерация с 1.
        //нумерация сделанная с 1, чтобы нумерацию промежутка для вставки можно было нумеровать с 0.
        //ind == 0 перед первым.
        //ind < 0 отсчёт с конца, где -1 послдений.

        //преобразование к общему виду.
        int ln = size();
        if (ind > ln) {
            ind = ln;
        }
        if (ind < 0) {
            ind = ln + ind + 1 < 0 ? 0 : ln + ind + 1;
        }

        //вставка.
        struct list *newElement;
        struct list *n;
        newElement = new struct list;
        newElement->data = value;newElement = new struct list;
        newElement->data = value;
        newElement->next = NULL;

        if (ind == 0) {
            newElement->next = head;
            head = newElement;
            return;
        } else {
            struct list *temp = head;
            for (; 1 < ind; --ind) {
                temp = temp->next;
            }
            newElement->next = temp->next;
            temp->next = newElement;
            return;
        }
    }

    void insertAfterValue(T newValue, T value) {
        //вставка после первого вхождения заданного значения.

        struct list *temp = head, *newElement;
        newElement = new struct list;
        newElement->data = newValue;
        newElement->next = NULL;

        //вставка
        while (temp->data != value) {
            temp = temp->next;
        }
        newElement->next = temp->next;
        temp->next = newElement;
        return;
    }

    void deleteElement(int ind) {
        //удаление элимента по индексу.

        //ind указывает какой элемент нужно удалить, нумерация с 0.
        //ind < 0 отсчёт с конца, где -1 послдений.

        if (head != NULL) {
            //преобразование к общему виду.
            int ln = size();
            if (ind > ln - 1) {
                ind = ln - 1;
            }
            if (ind < 0) {
                ind = ln + ind < 0 ? 0 : ln + ind;
            }

            //удаление.
            struct list *prevTemp = NULL, *currTemp = head;
            for (; 0 < ind; --ind) {
                prevTemp = currTemp;
                currTemp = currTemp->next;
            }
            if (prevTemp == NULL) {
                head = currTemp->next;
            } else {
                prevTemp->next = currTemp->next;
            }
            free(currTemp);
            return;
        }
    }

    void deleteValue(T value) {
        //удаление первого вхождения значения.

        if (head != NULL) {
            struct list *prevTemp = NULL, *currTemp = head;
            while (currTemp->data != value) {
                prevTemp = currTemp;
                currTemp = currTemp->next;
            }
            if (prevTemp == NULL) {
                head = currTemp->next;
            } else {
                prevTemp->next = currTemp->next;
            }
            free(currTemp);
            return;
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

    void print() {
        //вывод списка на экран

        struct list *temp = head;

        cout << "[ ";
        while (temp != NULL) {
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << "]\n";
    }

    int stupitstuff() {
        int count = 0;
        struct list *temp = head;
        while (temp != NULL) {
            if (temp->data < 0 && temp->data % 7 == 0) {
                count++;
            }
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    ifstream in("input.txt");

    List<int> l = List<int>();

    int n;
    while (in >> n) {
        l.insert(n, 0);
    }
    cout << l.stupitstuff() << endl;

    return 0;
}