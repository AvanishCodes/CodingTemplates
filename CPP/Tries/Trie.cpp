#include <string>
#include <iostream>
#include "TrieNode.cpp"
using namespace std;

struct Result
{
    bool found;
    string description;
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
    void insert(string word, string desc = "")
    {
        TrieNode *curr = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!curr->hasChild(word[i]))
                curr->setChild(word[i], new TrieNode());
            curr = curr->getChild(word[i]);
        }
        if (curr->isEOW())
        {
            cout << word << " Word is already present. Check your records.\n";
            return;
        }
        curr->setEndOfWord(true);
        curr->setDescription(desc);
        cout << word << " Word inserted successfully.\n";
    }
    Result search(string word)
    {
        TrieNode *curr = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!curr->hasChild(word[i]))
                return Result{0, ""};
            curr = curr->getChild(word[i]);
        }
        return Result{curr->isEOW(), curr->getDescription()};
    }
    bool startsWith(string prefix)
    {
        TrieNode *curr = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!curr->hasChild(prefix[i]))
                return false;
            curr = curr->getChild(prefix[i]);
        }
        return true;
    }
    // Delete a word from the Trie
    void deleteWord(string word)
    {
        TrieNode *curr = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!curr->hasChild(word[i]))
                return;
            curr = curr->getChild(word[i]);
        }
        if (!curr->isEOW())
        {
            cout << word << " Word is not present.\n";
            return;
        }
        curr->setEndOfWord(false);
        curr->setDescription("");
        cout << word << " Word deleted successfully.\n";
    }
};