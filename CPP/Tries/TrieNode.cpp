#include <iostream>
#include <string>
using namespace std;

class TrieNode
{
private:
    TrieNode *children[26];
    bool isEndOfWord;
    /*
     * bool isNoun;
     * bool isVerb;
     * bool isAdjective;
     * bool isAdverb;
     * bool isPronoun;
     * bool isPreposition;
     * bool isConjunction;
     * bool isInterjection;
     * bool isNumeral;
    **/
    string description;

public:
    // Constructor
    TrieNode()
    {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
    // Destructor
    ~TrieNode()
    {
        for (int i = 0; i < 26; i++)
            if (children[i] != NULL)
                delete children[i];
    }
    bool hasChild(char c)
    {
        return children[c - 'a'] != NULL;
    }
    TrieNode *getChild(char c)
    {
        return children[c - 'a'];
    }
    void setChild(char c, TrieNode *node)
    {
        children[c - 'a'] = node;
    }
    bool isEOW()
    {
        return isEndOfWord;
    }
    void setEndOfWord(bool b = false)
    {
        isEndOfWord = b;
    }
    void setDescription(string s)
    {
        description = s;
    }
    string getDescription()
    {
        return description;
    }

    bool hasDescription()
    {
        return description != "";
    }
    /*
     * void setNoun(bool b = true)
     * {
     *     isNoun = b;
     * }
     * bool isN()
     * {
     *     return isNoun;
     * }
     * void setVerb(bool b = true)
     * {
     *     isVerb = b;
     * }
     * bool isV()
     * {
     *     return isVerb;
     * }
     * void setAdj(bool b = true)
     * {
     *     isAdjective = b;
     * }
     * bool isAdj()
     * {
     *     return isAdjective;
     * }
     * void setAdv(bool b = true)
     * {
     *     isAdverb = b;
     * }
     * bool isAdv()
     * {
     *     return isAdverb;
     * }
     * void setPronoun(bool b = true)
     * {
     *     isPronoun = b;
     * }
     * bool isPron()
     * {
     *     return isPronoun;
     * }
     * void setPreposition(bool b = true)
     * {
     *     isPreposition = b;
     * }
     * bool isPrep()
     * {
     *     return isPreposition;
     * }
     * void setConjunction(bool b = true)
     * {
     *     isConjunction = b;
     * }
     * bool isConj()
     * {
     *     return isConjunction;
     * }
     * void setInterjection(bool b = true)
     * {
     *     isInterjection = b;
     * }
     * bool isInter()
     * {
     *     return isInterjection;
     * }
     * void setNumeral(bool b = true)
     * {
     *     isNumeral = b;
     * }
     * bool isNum()
     * {
     *     return isNumeral;
     * }
     **/
};