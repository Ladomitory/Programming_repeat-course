///
///Problem 10.2
///

//#include <stdio.h>
//#include <stdlib.h>
//#include <locale>
#include <fstream>
#include <iostream>

using namespace std;

const unsigned int INF = (int) 1e3;

int utf8_strlen(const string& str)
{
    int c,i,ix,q;
    for (q=0, i=0, ix=str.length(); i < ix; i++, q++)
    {
        c = (unsigned char) str[i];
        if      (c>=0   && c<=127) i+=0;
        else if ((c & 0xE0) == 0xC0) i+=1;
        else if ((c & 0xF0) == 0xE0) i+=2;
        else if ((c & 0xF8) == 0xF0) i+=3;
            //else if (($c & 0xFC) == 0xF8) i+=4; // 111110bb //byte 5, unnecessary in 4 byte UTF-8
            //else if (($c & 0xFE) == 0xFC) i+=5; // 1111110b //byte 6, unnecessary in 4 byte UTF-8
        else return 0;//invalid utf8
    }
    return q;
}

int main() {
    ifstream fin("input.txt");
    string word;
    int *a = (int*) calloc(INF, sizeof(int));
    while (fin >> word) {
        a[utf8_strlen(word)]++;
    }
    for (int i = 1; i < INF; ++i) {
        if (a[i] != 0) {
            cout << i << " - " << a[i] << endl;
        }
    }
    return 0;
}