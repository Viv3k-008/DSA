class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size() , ans = 0;

        for(int i = 0 ; i < n ; i++){
            unordered_map<char,int> m;
            for(int j = i ; j < n ; j++){
               m[s[j]]++;

                int first = -1;
                bool check = true;
                for(auto it : m){
                    if(first == -1){
                        first = it.second;
                    }
                    else if(first == it.second){
                        continue;
                    }
                    else {
                        check = false;
                        break;
                    }
                }
    
                if(check){
                    ans = max(ans , j-i+1);
                }
            }
            
        }

        return ans;
    }
};