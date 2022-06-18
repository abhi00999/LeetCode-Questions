
struct Node{
    Node *links[26];
    bool flag=false;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    
    void put(char ch, Node* node){
        links[ch-'a']= node;
    }
    
    // returns where char 'ch' is pointing to
    Node *get(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag=true;
    }
};

class Trie {
public:
    Node *root;
    Trie() {
        root = new Node();
    }
    
    // TC: O(len)
    void insert(string word) {
        Node *node= root;
        
        for(int i=0;i<word.length();i++){
            // means there is reference node for current character so we create one
            if(node->containsKey(word[i])==NULL){
                node->put(word[i], new Node() );
            }
            
            // Travel to next node(reference trie)
            node= node->get(word[i]);
        }
        
        // wherever the last node is pointing set that to true
        node->setEnd();
    }
    
    
    bool search(string word) {
        Node * node=root;
        for(int i=0;i<word.length();i++){
            if(node->containsKey(word[i]) == NULL){
                return false;
            }
            node= node->get(word[i]);
        }
        if(node->flag == true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node *node= root;
        
        for(int i=0;i<prefix.length();i++){
            if(node->containsKey(prefix[i]) == NULL){
                return false;
            }
            node= node->get(prefix[i]);
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