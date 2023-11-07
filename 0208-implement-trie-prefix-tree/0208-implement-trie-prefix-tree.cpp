struct Node
{
    Node* child[26];
    bool isEnd;
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
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
        Node* temp = root;
        for (auto& c : word)
        {
            if (temp->child[c - 'a'] == nullptr) return false;
            temp = temp->child[c - 'a'];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for (auto& c : prefix)
        {
            if (temp->child[c - 'a'] == nullptr) return false;
            temp = temp->child[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */