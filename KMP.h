#pragma once

#include<vector>
#include <string>
#include <algorithm>

using namespace std;

class KMP {
private:
    string text; //змінна тексту
    string pattern; //змінна слова
    vector<int> LPS; //вектор префікс-функції
    vector<string> splitted_text; //вектор розділених стрічок тексту

    //функція, яка розбиває текст на речення. Кожне речення зберігає у вектор
    void split(string s) {
        splitted_text.clear();
        int pos;
        while ((pos = s.find('.')) != string::npos) {
            splitted_text.push_back(s.substr(0, pos + 1));
            s.erase(0, pos + 1);

            // пропускаємо пробіли та переноси рядка перед наступним реченням
            while (!s.empty() && (s[0] == ' ' || s[0] == '\r' || s[0] == '\n')) {
                s.erase(0, 1);
            }
        }

        // залишок без крапки (якщо він є) теж вважаємо стрічкою
        if (!s.empty()) splitted_text.push_back(s);
    }

    //функція яка об'єднує розділені стрічки в текст
    string groupStringsIntoText(vector<string>& splitted) {
        string result = "";
        for (int i = 0;i < splitted.size();i++) {
            result += splitted[i];
            result += " ";
        }
        return result;
    }

    //функція, яка обраховує префікс-функцію
    void computeLPSArray(string& text, string& pattern, int pattern_size) {
        //створює вектор з розміром pattern_size і значенням 0
        LPS.assign(pattern_size, 0);
        //довжина збігу
        int length = 0;
        int i = 1;

        //пошук збігів
        while (i < pattern_size) {
            //якщо знайшли збіг - збільшуємо індекси
            if (pattern[i] == pattern[length]) {
                length++;
                LPS[i] = length;
                i++;
            }

            else {
                //якщо символи різні і довжина > 0, то беремо коротшу частину збігу
                if (length != 0) {
                    length = LPS[length - 1];
                }
                //якшо збігу взагалі немає
                else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }

    //алгоритм кнута
    vector<int> KMP_algorithm(string& text) {
        int pattern_size = pattern.length();
        int text_size = text.length();

        //вектор, в який записується на яких індексах є збіг слова
        vector<int> ans;

        int i = 0; // індекс для тексту
        int j = 0; // індекс для шуканого слова

        while (i < text_size) {

            //якщо знайшли збіг символа
            if (pattern[j] == text[i]) {
                i++;
                j++;
            }

            //якщо знайшли відразу все слово
            if (j == pattern_size) {
                ans.push_back(i - j);
                j = LPS[j - 1]; //індекс залишає ту частину кінця збігу, яка ще може бути початком наступного збігу
            }
      
            //якщо символи різні
            else if (i < text_size && pattern[j] != text[i]) {
                //частина зразка вже збіглася
                if (j != 0) {
                    j = LPS[j - 1];
                }
                //взагалі нема збігу
                else {
                    i++;
                }
            }
        }
        return ans;
    }

public:
    //геттер тексту
    string getText() const { return text; }
    //к-ть стрічок в тексті
    int stringCount() { return splitted_text.size(); }

    //знайти збіг в тексті (КМП)
    vector<int> findPattern() { return KMP_algorithm(text); }

    //створити об'єкт. Повертає false, якщо текст або слово пусте
    bool createObject(string& text, string& pattern) {
        if (text.empty() || pattern.empty()) return false;

        this->text = text;
        this->pattern = pattern;
        computeLPSArray(text, pattern, pattern.length());
        split(text);
        return true;
    }

    //індивідуальне завдання. 
    // Повертає false, якщо індекс n < 2 або більше к-ті речень
    // або індекс i < 1 або більше к-ть речень
    bool individualTask(int number_of_strings, int index_i, string& result_text, vector<int>& result_index) {
        
        if (number_of_strings < 2 || number_of_strings != splitted_text.size()) return false;
        if (index_i < 1 || index_i > number_of_strings) return false;
        
        vector<string> tmp = splitted_text;
        swap(tmp[index_i - 1], tmp[number_of_strings - 2]);
        result_text = groupStringsIntoText(tmp);
        result_index = KMP_algorithm(result_text);
        return true;
    }
};