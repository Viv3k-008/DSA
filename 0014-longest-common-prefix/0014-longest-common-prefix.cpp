class Solution {
public:
    class trieNode{
        public:
        vector<trieNode*> arr;
        bool isEnd;
        int cnt;

        trieNode(){
            isEnd = false;
            cnt = 0;
            arr.assign(26, NULL);
        }
    };

    void create(string& str, trieNode* root){
        trieNode* crawler = root;

        for(int i = 0 ; i < str.size(); i++){
            int idx = str[i]-'a';
            if(crawler->arr[idx] == NULL){
                crawler->arr[idx] = new trieNode();
            }

            crawler = crawler->arr[idx];
            crawler->cnt++;
        }
        crawler->isEnd = true;
    }
    int count(trieNode* root, int n){
        trieNode* crawler = root;
        int len = 0;
        for(int i = 0 ; i < 26; i++){
            if(crawler->arr[i] != NULL && crawler->arr[i]->cnt == n){
                len = max(len, 1 + count(crawler->arr[i], n));
            }
        }

        return len;
    }
    string longestCommonPrefix(vector<string>& strs) {
        trieNode* root = new trieNode();

        for(int i = 0 ; i < strs.size(); i++){
            create(strs[i], root);
        }

        int len = count(root, strs.size());
        return strs[0].substr(0, len);
    }
};