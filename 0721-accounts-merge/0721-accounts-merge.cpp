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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string,int> mp;

        DisjointSetUnion dsu(n);

        for(int i = 0 ; i < n ; i++){
            dsu.size[i]++;
            for(int j = 1 ; j < accounts[i].size() ; j++){
                string s = accounts[i][j];

                if(mp.size() == 0){
                    mp[s] = i;
                    continue;
                }

                if(mp.count(s)){
                    dsu.unionNode(i , mp[s]);
                    continue;
                }
                else mp[s] = i;
            }
        }
        vector<vector<int>> store(n);
        for(int i = 0 ; i < n ; i++){
            int par = dsu.par[i];
            store[par].push_back(i);
        }

        vector<vector<string>> mergeMails(n);

        for(auto it : mp){
            string email = it.first;
            int node = it.second;

            int par = dsu.root(node);
            mergeMails[par].push_back(email);
        }
        
        vector<vector<string>> ans;

        for(int i = 0 ; i < n ; i++){
            if(mergeMails[i].size() == 0) continue;
            sort(mergeMails[i].begin() , mergeMails[i].end());
            
            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for(string s : mergeMails[i]){
                temp.push_back(s);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};