#include <iostream>
#include <string>
#include <vector>

using namespace std;

// KMP algorithm for finding the first occurrence of a pattern in a text string
int kmp_search(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();
    // calculate prefix function for the pattern
    vector<int> pi(m);
    pi[0] = 0;
    int k = 0;
    for (int i = 1; i < m; i++) {
        while (k > 0 && pattern[k] != pattern[i]) {
            k = pi[k - 1];
        }
        if (pattern[k] == pattern[i]) {
            k++;
        }
        pi[i] = k;
    }
    // search for the pattern in the text
    k = 0;
    for (int i = 0; i < n; i++) {
        while (k > 0 && pattern[k] != text[i]) {
            k = pi[k - 1];
        }
        if (pattern[k] == text[i]) {
            k++;
        }
        if (k == m) {
            return i - m + 1;
        }
    }

    return -1;
}

// function to replace all occurrences of a pattern with a new string
string kmp_replace(const string &text, const string &pattern, const string &new_str) {
    string result = text;
    int pos = kmp_search(result, pattern);
    while (pos != -1) {
        result.replace(pos, pattern.length(), new_str);
        pos = kmp_search(result, pattern);
    }
    return result;
}

int main() {
    string text;
    cout << "Enter the text :";
    getline(cin, text);
    string pattern, new_str;
    cout << "Enter the pattern to find :";
    getline(cin, pattern);
    cout << "Enter the replacement text :";
    getline(cin, new_str);

    cout << endl << "Original text: " << text << endl;
    cout << "Pattern to replace: " << pattern << endl;
    cout << "New string: " << new_str << endl;
    string new_text = kmp_replace(text, pattern, new_str);
    cout << "New String: " << new_text << endl;
    return 0;
}
