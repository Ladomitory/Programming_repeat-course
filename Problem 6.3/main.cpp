#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

void upper(string& s) {
    for (char & i : s) {
        i = toupper(i);
    }
}

int main() {
    ifstream IF("input.txt");
    ofstream OF("output.txt");

    set<string> NotWords;
    string Line;
    getline(IF, Line);
    Line += ' ';
    string word;
    for (char e : Line) {
        if (e == ' ') {
            upper(word);
            NotWords.insert(word);
            word = "";
        } else {
            word += e;
        }
    }

    map<string, int> Words;
    while (IF >> word) {
        upper(word);
        for (int i = 0; i < word.size(); ++i) {
            if (!('A' <= word[i] && word[i] <= 'Z')) {
                word = word.substr(0, i);
                break;
            }
        }
        if (NotWords.find(word) == NotWords.end())
            Words.find(word) == Words.end() ? (Words[word] = 1) : (Words[word] += 1);
    }

    auto It = Words.begin(), maxIt = Words.begin();
    int Max = 0;
    while (It != Words.end()) {
        if (It->second > Max) {
            Max = It->second;
            maxIt = It;
        }
        ++It;
    }
    OF << maxIt->first << endl;
    IF.close();
    OF.close();
    return 0;
}