class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size() , m = arr2.size();

        unordered_map<string,bool> mp;
        for(int i = 0 ; i < m ; i++){
            string s = to_string(arr2[i]);

            string temp = "";
            for(char c : s){
                temp += c;
                mp[temp] = true;
            }
        }

        int maxi = 0;

        for(int i = 0 ; i < n ; i++){
            string s = to_string(arr1[i]);

            string temp = "";
            for(char c : s){
                temp += c;
                if(mp.count(temp)){
                    maxi = max(maxi , (int)temp.size());
                }
            }
        }

        return maxi;
    }
};