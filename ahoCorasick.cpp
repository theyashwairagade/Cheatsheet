struct TrieNode {
    vector<int> output; // Stores indices of strings ending at this node
    unordered_map<char, TrieNode*> children;
    TrieNode* fail = nullptr; // Failure link
};

class AhoCorasick {
    private:
        TrieNode* root;
        vector<string> patterns;

        void buildTrie(const vector<string>& patterns) {
            this->patterns = patterns;
            for (int i = 0; i < patterns.size(); i++) {
                TrieNode* node = root;
                for (char c : patterns[i]) {
                    if (!node->children.count(c))
                        node->children[c] = new TrieNode();
                    node = node->children[c];
                }
                node->output.push_back(i); // Store pattern index at end node
            }
        }

        void buildFailureLinks() {
            queue<TrieNode*> q;
            for (auto& pair : root->children) {
                pair.second->fail = root;
                q.push(pair.second);
            }

            while (!q.empty()) {
                TrieNode* curr = q.front();
                q.pop();

                for (auto& pair : curr->children) {
                    char c = pair.first;
                    TrieNode* child = pair.second;
                    TrieNode* failNode = curr->fail;

                    while (failNode && failNode->children.find(c) == failNode->children.end())
                        failNode = failNode->fail;

                    child->fail = (failNode) ? failNode->children[c] : root;

                    if (child->fail)
                        child->output.insert(child->output.end(), child->fail->output.begin(), child->fail->output.end());
                    
                    q.push(child);
                }
            }
        }
    public:
        AhoCorasick(const vector<string>& patterns) {
            root = new TrieNode();
            buildTrie(patterns);
            buildFailureLinks();
        }
        
        vector<vector<int>> search(const string& text) {
            vector<vector<int>> results(patterns.size());
            TrieNode* node = root;

            for (int i = 0; i < text.size(); ++i) {
                char c = text[i];
                while (node && node->children.find(c) == node->children.end())
                    node = node->fail;  // Follow fail links

                if (node) {
                    node = node->children[c];
                    for (int patternIndex : node->output)
                        results[patternIndex].push_back(i - patterns[patternIndex].size() + 1);
                } else {
                    node = root;
                }
            }
            return results;
        }
};

vector<vector<int>> findStringOccurrences(const vector<string>& patterns, const string& text) {
    AhoCorasick ahoCorasick(patterns);
    return ahoCorasick.search(text);
}


// This was for complete word
