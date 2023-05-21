#include <iostream>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode *> children;
    bool is_end;

    TrieNode() {
        is_end = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *current = root;
        for (char c: word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->is_end = true;
    }

    bool search(string word) {
        TrieNode *current = root;
        for (char c: word) {
            if (current->children.find(c) == current->children.end()) {
                return false;
            }
            current = current->children[c];
        }
        return current->is_end;
    }

private:
    TrieNode *root;
};

int main() {
    Trie trie;
    trie.insert("hello");
    trie.insert("world");
    trie.insert("hi");
    trie.insert("hey");

    cout << "Search for 'hello': " << trie.search("hello") << endl;
    cout << "Search for 'world': " << trie.search("world") << endl;
    cout << "Search for 'hey': " << trie.search("hey") << endl;
    cout << "Search for 'heya': " << trie.search("heya") << endl;

    return 0;
}
