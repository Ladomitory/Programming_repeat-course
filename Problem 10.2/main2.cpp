#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main()
{
    ifstream fin ("input.txt");
    string String;
    vector<int> Lengths(8192, 0);
    while (fin >> String)
        ++Lengths[strlen(String.c_str())];
    for (int i = 1; i < 8192; ++i)
        if (Lengths[i] > 0)
            cout << i << " - " << Lengths[i] << endl;
    return 0;
}