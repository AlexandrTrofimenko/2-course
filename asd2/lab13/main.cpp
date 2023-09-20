#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector<int> buildBadCharacterTable(string pattern) {
    vector<int> badCharacter(256, -1);
    int patternLength = pattern.length();
    for (int i = 0; i < patternLength; i++) {
        badCharacter[pattern[i]] = i;
    }
    return badCharacter;
}

vector<int> buildGoodSuffixTable(string pattern) {
    int patternLength = pattern.length();
    vector<int> goodSuffix(patternLength + 1, 0);

    int i = patternLength, j = patternLength + 1;
    goodSuffix[i] = j;

    while (i > 0) {
        while (j <= patternLength && pattern[i - 1] != pattern[j - 1]) {
            if (goodSuffix[j] == 0) {
                goodSuffix[j] = j - i;
            }
            j = goodSuffix[j];
        }
        i--;
        j--;
        goodSuffix[i] = j;
    }

    j = goodSuffix[0];
    for (i = 0; i <= patternLength; i++) {
        if (goodSuffix[i] == 0) {
            goodSuffix[i] = j;
        }
        if (i == j) {
            j = goodSuffix[j];
        }
    }

    return goodSuffix;
}

vector<int> boyerMooreSearch(string text, string pattern) {
    vector<int> occurrences;
    int textLength = text.length();
    int patternLength = pattern.length();

    vector<int> badCharacter = buildBadCharacterTable(pattern);
    vector<int> goodSuffix = buildGoodSuffixTable(pattern);

    int shift = 0;
    while (shift <= textLength - patternLength) {
        int j = patternLength - 1;
        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }

        if (j < 0) {
            occurrences.push_back(shift);
            shift += goodSuffix[0];
        }
        else {
            shift += max(goodSuffix[j + 1], j - badCharacter[text[shift + j]]);
        }
    }

    return occurrences;
}

int main() {
    setlocale(LC_ALL, "Rus");
    ifstream in("input.txt");
    if (!in) { return 2; }
    string text; in >> text;
    cout << text << endl;
    string pattern = "AB";
    vector<int> occurrences = boyerMooreSearch(text, pattern);

    if (occurrences.empty()) {
        cout << "Образец не найден в строке." << endl;
    }
    else {
        cout << "Образец найден в следующих позициях: ";
        for (int i : occurrences) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}