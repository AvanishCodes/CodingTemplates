#include <iostream>
#include <string.h>
#include <vector>
#include <map>
using namespace std;

bool flag = false;

// A trie node has a character, status for end of string and a child pointer.
class Node
{
  char ch;                  // character
  bool isTerminal;          // True if this is a terminal node.
  map<char, Node> children; // children is a map from char to TrieNode
public:
  Node();                         // Default constructor
  Node(char);                     // Constructor with character
  Node(char, bool);               // Constructor
  bool is_terminal();             // Return true if this is a terminal node.
  void set_terminal(bool);        // Set isTerminal to true.
  Node get_child(char);           // Return child node with given character.
  Node set_child(Node);           // Set child node with given character.
  bool has_any_child();           // Return true if this node has a child with given character.
  map<char, Node> get_children(); // Return a map from char to child node.
  int number_of_children();       // Return number of children.
  char get_ch();                  // Return character.
};

// Construct a trie node with a character.
Node::Node(char ch, bool isTerminal)
{
  this->ch = ch;
  this->isTerminal = isTerminal;
  children = map<char, Node>();
}
// Constructor with character
Node::Node(char ch)
{
  this->ch = ch;
  this->isTerminal = false;
  children = map<char, Node>();
}
// Default constructor
Node::Node()
{
  this->ch = '\0';
  this->isTerminal = false;
  children = map<char, Node>();
}

// Get the terminal status of this node.
bool Node::is_terminal()
{
  return this->isTerminal;
}

// Set the terminal status of this node.
void Node::set_terminal(bool isTerminal)
{
  this->isTerminal = isTerminal;
}

// Get a child node of this node.
Node Node::get_child(char ch)
{
  if (this->children.find(ch) == this->children.end())
  {
    Node n = Node();
    return n;
  }
  Node ret_value = this->children[ch];
  return ret_value;
  // return Node();
}

// Get the number of children of this node.
int Node::number_of_children()
{
  return this->children.size();
}

// Set a child node of this node.
Node Node::set_child(Node node)
{
  this->children[node.ch] = node;
  // cout << "Added " << node.ch << " to " << this->get_ch() << endl;
  return node;
}

// Has node any child?
bool Node::has_any_child()
{
  return this->children.size() > 0;
}

// Return a map from char to child node.
map<char, Node> Node::get_children()
{
  // cout << "map size: " << this->children.size() << endl;
  return this->children;
}

// Return character.
char Node::get_ch()
{
  return this->ch;
}

// Implement the tries data structure.
class Trie
{

  Node root;      // root node
  int totalWords; // total number of words in the trie.
public:
  Trie();                                    // Constructor
  void addWord(string s);                    // Inserts a string into the trie.
  void addWord(Node root2, string word);     // Inserts a string into the trie.
  bool searchWord(string s);                 // Searches for a string in the trie.
  bool searchWord(Node root2, string word);  // Searches for a string in the trie.
  void removeWord(string s);                 // Removes a string from the trie.
  void removeWord(Node root2, string word);  // Removes a string from the trie.
  void displayWords();                       // Prints all the words in the trie.
  void displayWords(Node root2, string ssf); // Prints words constructed from the given root.
  int getTotalWords();                       // Return the total number of words in the trie.
  Node getRoot();                            // Return the root node.
};

// Constructor
Trie::Trie()
{
  this->root = Node();  // Create a new root node.
  this->totalWords = 0; // Initialize the total number of words in the trie.
}

// Return root
Node Trie::getRoot()
{
  return this->root;
}

// Add a string to the trie.
void Trie::addWord(string s)
{
  this->addWord(this->root, s); // Call the helper function.
}

// Helper function to add a string to the trie.
void Trie::addWord(Node Parent, string word)
{
  // If the string is empty, then we are done.
  if (word.size() == 0) // If the string is empty, return true.s
  {
    if (!Parent.is_terminal())
      Parent.set_terminal(true), this->totalWords++;
    return; // Added the string to the trie.
  }

  // Recursivly add the rest of the string.
  char ch = word[0];                            // Get the first character.
  string s = word.substr(1, word.length() - 1); // Get the rest of the string.
  // Check if the character is already in the trie.
  if (Parent.get_child(ch).get_ch() == '\0')
  {
    // If not, create a new node.
    Node temp = Node(ch, false);         // Create a new node.
    Node child = Parent.set_child(temp); // Get the child node.
    return this->addWord(child, s);      // Recursively add the rest of the string.
  }
  else
  {
    return this->addWord(Parent.get_child(ch), s); // Recursively add the rest of the string.
  }
}

// Search for a string in the trie.
bool Trie::searchWord(string s)
{
  return this->searchWord(this->root, s); // Call the helper function.
}

// Helper function to search for a string in the trie.
bool Trie::searchWord(Node Parent, string word)
{
  // If the string is empty, then we are done.
  if (word.size() == 0) // If the string is empty, return true.
  {
    if (Parent.is_terminal())
      return true; // Found the string in the trie.
    else
      return false; // Did not find the string in the trie.
  }
  // return true;
  char ch = word[0];                            // Get the first character.
  string s = word.substr(1, word.length() - 1); // Get the rest of the string.

  Node child = Parent.get_child(ch); // Get the child node.

  cout << "Returned: " << child.get_ch() << endl;

  // if (&child == NULL)          // If the child node does not exist.
  //   return false;              // Return false.
  return searchWord(child, s); // Recursively search the rest of the string.
}

// Remove a string from the trie.
void Trie::removeWord(string s)
{
  this->removeWord(this->root, s); // Call the helper function.
}

// Helper function to remove a string from the trie.
void Trie::removeWord(Node Parent, string word)
{
  // If the string is empty, then we are done.
  if (word.size() == 0) // If the string is empty, return true.
  {
    if (Parent.is_terminal())
      Parent.set_terminal(false), this->totalWords--;
    return;
  }
  // Recursively remove the rest of the string.
  char ch = word[0];                            // Get the first character.
  string s = word.substr(1, word.length() - 1); // Get the rest of the string.
  Node child = Parent.get_child(ch);            // Get the child node.

  if (&child == NULL) // If the child node does not exist.
    return;           // Return.

  // If the curent node is not a terminal node,and has no branches, then we need to remove the child node.
  if (!child.has_any_child() && !child.is_terminal()) // If the string is empty, remove the child node.)
    this->removeWord(child, s);                       // Recursively remove the rest of the string.
}

// Print all the words in the trie.
void Trie::displayWords()
{
  printf("---------------------------------\n");
  this->displayWords(this->root, ""); // Call the helper function.
  printf("---------------------------------\n");
}

// Helper function to print all the words for a node in the trie.
void Trie::displayWords(Node root2, string ssf)
{
  // If the node is a terminal node, then print the word.
  if (root2.is_terminal())
  {
    cout << ssf << '\n';
    return;
  }
  // Recursively print the words for the children.
  // cout << ssf + "Hi";
  for (map<char, Node>::iterator it = root2.get_children().begin(); it != root2.get_children().end(); it++)
  {
    cout << "Suspected zone";
    this->displayWords(it->second, string(ssf + it->first));
    cout << it->first;
  }
  map<char, Node> children = root2.get_children();
  cout << "Check " << children.size() << "\n";
  //  mymap = root2.get_children();

  for (auto element : root2.get_children())
    cout << typeid(element).name() << " ";
  return;
}

// Get the total number of words in the trie.
int Trie::getTotalWords()
{
  return this->totalWords; // Return the total number of words in the trie.
}

// Driver program to test above functions
void test()
{
  Node root('a', false);
  // cout << "Node: " << root.get_ch() << endl;

  // Set the chlid node.
  Node child('b', false);
  cout << "Node: " << child.get_ch() << endl;
  // cout << a.get_children() << endl;
  root.set_child(child);
  Node child2('c', false);
  root.set_child(child2);
  for (auto i : root.get_children())
    cout << "Node : " << i.first << " ";
  map<char, Node> children = root.get_children();
  cout << "Check " << children.size() << "\n";
  // Ge the child node of a node.
  // Node child2 = root.get_child('b');
  // cout << "Node: " << child2.get_ch() << endl;
  cout << "Node: " << root.get_child('b').get_ch() << endl;
}

// Driver code
int main()
{
  // test();
  Trie variable;
  // Add some words to the trie.
  variable.addWord("cat");
  variable.addWord("cats");
  // variable.addWord("catfish");
  // variable.addWord("avanish");
  // variable.addWord("catalog");
  cout << "Total words: " << variable.getTotalWords() << endl;
  // Search for a word in the trie.
  // if (variable.searchWord("cat"))
  //   printf("Found word 'cat'\n");
  // else
  //   printf("Word 'cat' not found\n");
  cout << variable.getRoot().has_any_child() << endl;
  // Print all the words in the trie.
  // Get the first character of the word.
  // cout << variable.searchWord("cat") << endl;
  // variable.displayWords();

  // Testing Node

  return 0;
}

/**
 * @brief Testing Node
 *   Node root('a', false);

  cout << "Node: " << root.get_ch() << endl;

  // Set the chlid node.
  Node child('b', false);
  cout << "Node: " << child.get_ch() << endl;
  root.set_child(child);
  // Ge the child node of a node.
  Node child2 = root.get_child('b');
  cout << "Node: " << child2.get_ch() << endl;

  // Set child of b
  Node child3('c', false);
  cout << "Node: " << child3.get_ch() << endl;
  child.set_child(child3);
  // Get the child node of b node
  Node child4 = child.get_child('c');
  cout << "Node: " << child4.get_ch() << endl;

  // Add d as a child of a
  Node child5('d', false);
  cout << "Node: " << child5.get_ch() << endl;
  root.set_child(child5);
  // Get the child node of a node
  Node child6 = root.get_child('d');
  cout << "Node: " << child6.get_ch() << endl;

  // Has a any child?
  string result = root.has_any_child() ? "YES" : "NO";
  if (result == "YES")
  {
    cout << "Has a any child? " << result << endl;
    cout << "a has " << root.get_children().size() << " children" << endl;
  }
 * 
 */