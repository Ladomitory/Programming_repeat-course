//
//Project List
//Main File
//By Ladomitory
//On 03/11/2021
//

#include <iostream>

using namespace std;

template <class T>
class List {
private:
    typedef struct list {
        T data;
        struct list *next;
    }list;
    struct list *head;
public:
    List() {
        head = new list;
        head = NULL;
    }

    int size() {
        //возвращяет число элиментов.

        int ln = 0;
        list *temp = head;
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
        list *newElement;
        list *n;
        newElement = new list;
        newElement->data = value;
        newElement->next = NULL;

        if (ind == 0) {
            newElement->next = head;
            head = newElement;
            return;
        } else {
            list *temp = head;
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

        list *temp = head, *newElement;
        newElement = new list;
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

    void sort_insert(T value) {
        //сортирующее заполнение.

        list *prevTemp = NULL,  *currTemp = head, *newElement;
        newElement = new list;
        newElement->data = value;
        newElement->next = NULL;

        if (head == NULL) {
            head = newElement;
            return;
        }

        //вставка.
        while (currTemp->data < value) {
            prevTemp = currTemp;
            currTemp = currTemp->next;
            if (currTemp == NULL)
                break;
        }

        if (currTemp == NULL) {
            prevTemp->next = newElement;
            return;
        } else if (currTemp->data == value) {
            return;
        } else if (prevTemp == NULL) {
            newElement->next = head;
            head = newElement;
            return;
        } else {
            prevTemp->next = newElement;
            newElement->next = currTemp;
            return;
        }
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
            list *prevTemp = NULL, *currTemp = head;
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
            list *prevTemp = NULL, *currTemp = head;
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

        list *temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }
    }

    void print() {
        //вывод списка на экран

        list *temp = head;

        cout << "[ ";
        while (temp != NULL) {
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << "]\n";
    }

    T value(long long int ind) {
        //возвращает значение элемента на определённом месте списка.
        list *temp = head;
        int ln = size();
        for (int i = 0; i < ind && i < ln; ++i) {
            temp = temp->next;
        }
        return temp->data;
    }

    T operator[](long long int ind);
};

template <class T>
T List<T>::operator[](long long ind) {return value(ind);}

int main() {
    string command = " ";
    int ind, value, newValue;

    List<int> L = List<int>();

    do {
        //basic
        if (command == "ii") {
            cin >> ind >> newValue;
            L.insert(newValue, ind);
        } else if (command == "iv") {
            cin >> value >> newValue;
            L.insertAfterValue(newValue, value);
        } else if (command == "di") {
            cin >> ind;
            L.deleteElement(ind);
        } else if (command == "dv") {
            cin >> value;
            L.deleteValue(value);
        } else if (command == "mn") {
            L.makenull();
        } else if (command == "p") {
            L.print();
        } else if (command == "m") {
            L.merge(L);
        } else {}

        cin >> command;
    } while (command != "0");

    return 0;
}