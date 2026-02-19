class DisjointSetUnion{
        public:
        vector<int> par;
        vector<int> size;
        int components;
        DisjointSetUnion(int n){
            par.resize(n);
            size.resize(n , 1);
            components = n;
            for(int i = 0 ; i < n ; i++){
                par[i] = i;
            }
        }
        
        int root(int i){
            if(i == par[i]){
                return i;
            }
            
            return par[i] = root(par[i]);
        }
        
        int find(int u , int v){
            return root(u) == root(v);
        }
        
        bool unionNode(int i , int j){
            int u = root(i);
            int v = root(j);
            
            if(u == v){
                return false;
            }
            
            if(size[u] > size[v]){
                swap(u , v);  // u tree size should be smaller
            }
            
            par[u] = v;
            size[v] += size[u];
            components -= 1;
            return true;
        }
        
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        DisjointSetUnion dsu(n);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(isConnected[i][j]){
                    dsu.unionNode(i,j);
                }
            }
        }

        return dsu.components;
    }
};