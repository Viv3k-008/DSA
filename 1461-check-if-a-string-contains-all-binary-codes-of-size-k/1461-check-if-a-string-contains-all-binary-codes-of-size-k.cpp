class Solution {
public:
    // map<string,int> mp;
    // void form(int i , string& s , int k){
    //     if(i == k){
    //         mp[s]++;
    //         return;
    //     }

    //     for(int j = 0 ; j < 2 ; j++){
    //         s.push_back(j+'0');
    //         form(i+1 , s , k);
    //         s.pop_back();
    //     }

    // }
    bool hasAllCodes(string s, int k) {
        if(s.size() < k) return false;
        string temp = "";
        // form(0 , temp , k);
        map<string,int> mp2;
        for(int i = 0 ; i <= s.size()-k ; i++){
            string temp = "";
            for(int j = i ; j < i+k ; j++){
                temp += s[j];
            }
            mp2[temp]++;
        }

        return mp2.size() >= pow(2,k);
    }
};