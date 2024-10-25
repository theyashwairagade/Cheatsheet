#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Trie {
private:
    class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        bool isEndOfWord;

        TrieNode() 
            {isEndOfWord = false;}
    };
    TrieNode* root;

public:
    Trie() 
        {root = new TrieNode();}

    void insert(const string &word) 
    {
        TrieNode* node = root;
        for (char ch : word) 
        {
            if (node->children.find(ch) == node->children.end())
                node->children[ch] = new TrieNode();
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    void buildTrieUsing(const vector<string> &vec){
        for(auto &str: vec)
            insert(str);
    }

    bool search(const string &word) 
    {
        TrieNode* node = root;
        for (char ch : word) 
        {
            if (node->children.find(ch) == node->children.end())
                return false;
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }

    bool startsWith(const string &prefix) 
    {
        TrieNode* node = root;
        for (char ch : prefix) 
        {
            if (node->children.find(ch) == node->children.end())
                return false;
            node = node->children[ch];
        }
        return true;
    }
};
int main()
{
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;   // returns true
    cout << trie.search("app") << endl;     // returns false
    cout << trie.startsWith("app") << endl; // returns true
    trie.insert("app");
    cout << trie.search("app") << endl;     // returns true

    return 0;
}