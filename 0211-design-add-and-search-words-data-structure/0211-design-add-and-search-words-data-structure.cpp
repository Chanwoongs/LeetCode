struct Node
{
    Node* child[26] = {nullptr, };
    bool isEnd = false;
};

class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* temp = root;
        
        for (auto& c : word)
        {
            if (temp->child[c - 'a'] == nullptr)
            {
                temp->child[c - 'a'] = new Node();
            }
            temp = temp->child[c - 'a'];
        }
        temp->isEnd = true;
    }
    
bool search(string word) {
    queue<Node*> nodes;
    nodes.push(root);
        
    for (auto& c : word) {
        int size = nodes.size();
        if (size == 0) {
            return false;
        }
                
        if (c == '.') {
            for (int i = 0; i < size; i++) {
                auto cur = nodes.front();
                nodes.pop();
                    
                for (int j = 0; j < 26; j++) {
                    if (cur->child[j] != nullptr) {
                        nodes.push(cur->child[j]);
                    }
                }
            }
        } else {
            for (int i = 0; i < size; i++) {
                auto cur = nodes.front();
                nodes.pop();
                if (cur->child[c - 'a'] != nullptr) {
                    nodes.push(cur->child[c - 'a']);
                }
            }
        }
    }

    while (!nodes.empty()) {
        auto node = nodes.front();
        nodes.pop();
        if (node->isEnd) {
            return true;
        }
    }

    return false;
}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */