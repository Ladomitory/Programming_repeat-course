//
//By Ladomitory from 29.10
//

#include <fstream>
#include <string>
#include <map>

using namespace std;

map<char,int> Symbols;

void Add(char ch) {
    if (Symbols.find(ch) == Symbols.end()) {
        Symbols[ch] = 1;
    } else {
        Symbols[ch] += 1;
    }
}

void Print(const string& namefile) {
    ofstream OF(namefile);
    auto It = Symbols.begin();
    while (It != Symbols.end()) {
        if ((int) It->first >= 12) {
            OF << (int) It->first << " : " << It->first << " - " << It->second << endl;
        }
        ++It;
    }
}

int main() {
    ifstream IF("input.txt");
    string str;
    while (getline(IF, str)) {
        for (char ch : str) {
            Add(ch);
        }
    }
    Print("output.txt");
    return 0;
}