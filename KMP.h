#pragma once

#include<vector>
#include <string>
#include <algorithm>

using namespace std;

class KMP {
private:
    string text;
    string pattern;
    vector<int> LPS;
    vector<string> splitted_text;

    //функція для підрахунку стрічок в тексті(за крапками в кінці кожного речення)
    int countN() {
        int count = 0;
        for (int i = 0;i < text.size();i++) {
            if (text[i] == '.') count++;
        }
        return count;
    }

    //функція, яка розбиває текст на речення. Кожне речення зберігає у вектор
    vector<string> split(string s) {

        vector<string> tokens;
        int pos = 0;
        string token;

        while ((pos = s.find('.')) != string::npos) {
            token = s.substr(0, pos);
            tokens.push_back(token);
            s.erase(0, pos + 1);
        }

        tokens.push_back(s);

        return tokens;
    }

    //функція яка об'єднує розділені стрічки в текст
    string groupStringsIntoText() {
        string result = "";
        for (int i = 0;i < splitted_text.size();i++) {
            result += splitted_text[i];
            result += ". ";
        }
        return result;
    }

    // Function to compute the LPS array
    void computeLPSArray(string& text, string& pattern, int pattern_size) {
        int length = 0;
        LPS[0] = 0; // LPS[0] is always 0
        int i = 1;

        while (i < pattern_size) {
            if (pattern[i] ==
                pattern[length]) {
                length++;
                LPS[i] = length;
                i++;
            }
            else {
                if (length != 0) {
                    length = LPS[length - 1];
                }
                else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }


public:

    KMP(string text, string pattern) {
        this->text = text;
        this->pattern = pattern;
        computeLPSArray(text, pattern, pattern.length());
        splitted_text = split(text);
    }


    // KMP algorithm to search for
// pattern in text
    vector<int> KMP_algorithm(string& text, string& pattern) {
        int pattern_size = pattern.length();
        int text_size = text.length();

        // Array for storing the starting index
        // of text, where the pattern exist
        vector<int> ans;

        vector<int> LPS(pattern_size);
        computeLPSArray(text,pattern,pattern_size);

        int i = 0; // index for text
        int j = 0; // index for pattern
        while (i < text_size) {

            // When character matches so we
            // have to increase both the pointers
            if (pattern[j] == text[i]) {
                i++;
                j++;
            }

            // When the pattern is completely matched,
            // store the starting position of text,
            // Where the pattern exist
            if (j == pattern_size) {
                ans.push_back(i - j);
                j = LPS[j - 1];
            }
            // When the character is not matched,
            // we have to move to previous index up
            // to which the matches take place
            else if (i < text_size && pattern[j]
                != text[i]) {
                if (j != 0) {
                    j = LPS[j - 1];
                }
                else {
                    i++;
                }
            }
        }
        return ans;
    }


    void individualTask(int number_of_strings, int index_i) {
        
        if (number_of_strings < 2 && number_of_strings != countN()) return;
        if (index_i > 1 && index_i < number_of_strings) return;

      
    }
};


