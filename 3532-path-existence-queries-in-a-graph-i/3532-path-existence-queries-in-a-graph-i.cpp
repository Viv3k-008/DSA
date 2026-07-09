class DisjointSetUnion{
public:
     vector<int> parent;
     vector<int> size;
     int components;
       
       DisjointSetUnion(int n){
         components = n;
         parent.resize(n);
         for(int i = 0 ; i < n ; i++) parent[i] = i;
         size.resize(n,1);
       }

       int root(int i){
          if(i == parent[i]){
            return i;
          }

          return parent[i] = root(parent[i]);
       }

       bool find(int u, int v){
        return root(u) == root(v);
       }

       bool UnionNode(int a, int b){
        int u = root(a);
        int v = root(b);

        if(u == v) return false;

        if(size[u] > size[v]){
            swap(u,v);
        }

        parent[u] = v;
        size[v] += size[u];
        components--;
        return true;
       }
    
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<vector<int>> edges;
        DisjointSetUnion dsu(n);
        
        int l = 0, r = 1;
        while(r < n){
            if(l == r){
                r++;
            }
            else{
                if((nums[r]-nums[l]) <= maxDiff){
                    if(!dsu.find(l,r)){
                        dsu.UnionNode(l,r);
                    }
                    r++;
                }
                else l++;
            }
        }

        vector<bool> ans;
        int m = queries.size();

        for(int i = 0 ; i < m ; i++){
            int l = queries[i][0], r = queries[i][1];
            if(dsu.find(l,r)){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }

        return ans;
    }
};