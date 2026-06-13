class TreeAncestor {
public:
    int LOG = 30;
    vector<vector<int>> up;
    void preCompute(int n , vector<int>& parent){
        for(int i = 0 ; i < n ; i++){
            up[i][0] = parent[i];
        }

        for(int j = 1 ; j < LOG ; j++){
            for(int i = 0 ; i < n ; i++){
                if(up[i][j-1] != -1){
                    up[i][j] = up[up[i][j-1]][j-1];
                }
                else up[i][j] = -1;
            }  
        }
    }
    TreeAncestor(int n, vector<int>& parent) {
        up.resize(n , vector<int>(LOG , -1));

        preCompute(n , parent);
    }
    
    int getKthAncestor(int x, int k) {
        for(int i = 0 ; i < LOG ; i++){
            if(k & (1 << i)){
                x = up[x][i];
                if(x == -1){
                    return -1;
                }
            }
        }
        return x;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */