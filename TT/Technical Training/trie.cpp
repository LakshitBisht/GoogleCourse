#include <iostream>
#include <unordered_map>

using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isEndOfWord;

    TrieNode()
    {
        isEndOfWord = false;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *current = root;

        for (char ch : word)
        {
            if (current->children.find(ch) == current->children.end())
            {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }

        current->isEndOfWord = true;
    }

    bool search(string word)
    {
        TrieNode *current = root;

        for (char ch : word)
        {
            if (current->children.find(ch) == current->children.end())
            {
                return false;
            }
            current = current->children[ch];
        }

        return current->isEndOfWord;
    }
};

int main()
{
    Trie trie;

    // Inserting words into the Trie
    trie.insert("apple");
    trie.insert("banana");
    trie.insert("car");
    trie.insert("cat");

    // Searching for words
    cout << trie.search("apple") << endl;  // Output: 1 (true)
    cout << trie.search("banana") << endl; // Output: 1 (true)
    cout << trie.search("car") << endl;    // Output: 1 (true)
    cout << trie.search("cat") << endl;    // Output: 1 (true)
    cout << trie.search("dog") << endl;    // Output: 0 (false)

    return 0;
}
