class Trie {
public:
    struct TrieNode{
        TrieNode* arr[26];
        bool isEnd;
    };
    TrieNode* getNode(){
        TrieNode* newNode = new TrieNode();

        for(int i = 0 ; i < 26 ; i++){
            newNode->arr[i] = NULL;
        }
        newNode->isEnd = false;
        return newNode;
    }

    TrieNode* root;

    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        TrieNode* crawler = root;

        for(int i = 0 ; i < word.size(); i++){
            int idx = word[i]-'a';
            if(crawler->arr[idx] == NULL){
                crawler->arr[idx] = getNode();
            }
            crawler = crawler->arr[idx];
        }
        crawler->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* crawler = root;

        for(int i = 0 ; i < word.size(); i++){
            int idx = word[i]-'a';
            if(crawler->arr[idx] == NULL){
                return false;
            }
            crawler = crawler->arr[idx];
        }
        if(crawler != NULL && crawler->isEnd == true){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* crawler = root;

        for(int i = 0 ; i < prefix.size(); i++){
            int idx = prefix[i]-'a';
            if(crawler->arr[idx] == NULL){
                return false;
            }
            crawler = crawler->arr[idx];
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