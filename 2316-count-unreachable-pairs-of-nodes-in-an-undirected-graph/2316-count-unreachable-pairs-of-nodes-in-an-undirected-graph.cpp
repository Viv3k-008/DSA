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
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSetUnion dsu(n);

        for(auto it : edges){
            if(!dsu.find(it[0],it[1])){
                dsu.unionNode(it[0],it[1]);
            }
        }

        vector<int> componentsSizes;

        for(int i = 0 ; i < dsu.par.size() ; i++){
            if(dsu.par[i] == i){
                componentsSizes.push_back(dsu.size[i]);
            }
        }

        long long sum = 0 , total = n;
        for(int i = 0 ; i < dsu.components ; i++){
            total -= componentsSizes[i];

            sum += (long long) (componentsSizes[i]*total);
        }

        return sum;
    }
};