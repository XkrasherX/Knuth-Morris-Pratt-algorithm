#pragma once

#include<vector>
#include <string>

using namespace std;

// Function to compute the LPS array
void computeLPSArray(string pattern,
    int m, vector<int>& LPS) {
    int length = 0;
    LPS[0] = 0; // LPS[0] is always 0
    int i = 1;

    while (i < m) {
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

// KMP algorithm to search for
// pattern in text
vector<int> KMP(string pattern,
    string text) {
    int m = pattern.length();
    int n = text.length();

    // Array for storing the starting index
    // of text, where the pattern exist
    vector<int> ans;

    vector<int> LPS(m);
    computeLPSArray(pattern, m, LPS);

    int i = 0; // index for text
    int j = 0; // index for pattern
    while (i < n) {

        // When character matches so we
        // have to increase both the pointers
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        // When the pattern is completely matched,
        // store the starting position of text,
        // Where the pattern exist
        if (j == m) {
            ans.push_back(i - j);
            j = LPS[j - 1];
        }
        // When the character is not matched,
        // we have to move to previous index up
        // to which the matches take place
        else if (i < n && pattern[j]
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