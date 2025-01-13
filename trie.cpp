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







// XOR Trie
struct xorTrie {
    static constexpr int max_b = 1 << 19;
    xorTrie *p[2] = {};
    void insert(int n) {
        xorTrie *r = this;
        for (int b = max_b; b > 0; b >>= 1) {
            int bit = (n & b) > 0;
            if (r->p[bit] == nullptr)
                r->p[bit] = new xorTrie();
            r = r->p[bit];
        }
    }
    bool remove(int n, int b = max_b) {
        if (b == 0)
            return true;
        int bit = (n & b) > 0;
        if (p[bit] != nullptr && p[bit]->remove(n, b >> 1)) {
            delete p[bit];
            p[bit] = nullptr;
        }
        return p[0] == p[1]; // both are nullptr
    }    
    int maxXor(int n) {
        int res = 0;
        xorTrie *r = this;
        for (int b = max_b; b > 0; b >>= 1)
            if (int bit = (n & b) > 0; r->p[!bit] != nullptr) {
                res += b;
                r = r->p[!bit];
            }
            else
                r = r->p[bit];
        return res;
    }  
};