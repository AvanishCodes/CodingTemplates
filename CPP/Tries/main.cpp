#include <iostream>
#include <vector>
#include <string>
#include "Trie.cpp"
using namespace std;

int main()
{
    Trie trie;

    // Insert Operations
    trie.insert("hello", "Hello is a greeting!");
    trie.insert("world");
    trie.insert("hell");
    trie.insert("he");
    trie.insert("her");
    trie.insert("hello");

    // Search Operations
    bool res;
    vector<string> words = {"hello", "hell", "he", "her", "world", "worl"};
    for (auto word : words)
    {
        res = trie.search(word).found;
        cout << "Searching for '" << word << "' : " << (string)(res ? "Found" : "Not found") << endl;
        if (res)
        {
            string desc = trie.search(word).description;
            if (desc != "")
                cout << "Description found: " << desc << endl;
        }
    }
    // Delete world from the Trie
    trie.deleteWord("world");
    res = trie.search("world").found;
    cout << "Searching for 'world' : " << (string)(res ? "Found" : "Not found") << endl;
    return 0;
}