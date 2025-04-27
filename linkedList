class Node{

public:
    int val;
    Node* next;

    Node(int val): val(val), next(nullptr) {}
};


class LinkedList {
    Node* root;

public:
    LinkedList(vector<int>& vec) {
        if (vec.empty()) {
            root = nullptr;
            return;
        }

        root = new Node(vec[0]);
        Node* node = root;
        for (int i = 1; i < vec.size(); ++i) {
            node->next = new Node(vec[i]);
            node = node->next;
        }
    }

    vector<int> getInVector(){
        vector<int> ans;
        Node* node = root;

        while(node){
            ans.push_back(node->val);
            node = node->next;
        }
        return ans;
    }
};