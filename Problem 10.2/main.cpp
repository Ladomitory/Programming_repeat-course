///
///Problem 10.2
///

#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

const unsigned int INF = (int) 1e3;

int main() {
    ifstream fin("input.txt");
    string word;
    int *a = (int*) calloc(INF, sizeof(int));
    while (fin >> word) {
        a[strlen(word.c_str())]++;
        //Судя по всему сохраняемое при заполнении string.length() считается криво
        //А strlen перебирает их заново. Но работает, только с char*, по этому используем преобразование
        //Почему это происходит? Вопрос хороший, ответ я не нашёл.
        //Илья Андреевич, если вы это смотрите, объясните почему так? И как можно было иначе?
    }
    fin.close();

    ofstream fout;
    fout.open("output.txt");
    for (int i = 1; i < INF; ++i) {
        if (a[i] != 0) {
            fout << i << " - " << a[i] << endl;
        }
    }
    fout.close();

    free(a);
    return 0;
}