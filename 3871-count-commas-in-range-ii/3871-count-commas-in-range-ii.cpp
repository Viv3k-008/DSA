class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        long long counts[13] = {1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000,1000000000000,10000000000000,100000000000000,1000000000000000};

        for(int i = 12; i >= 0; i--){
            string s = to_string(counts[i]);
            int comas = (s.size()%3 > 0)? s.size()/3 : (s.size()/3)-1;
            if(n > counts[i]-1){
                cout<<counts[i]<<endl;
                ans += 1LL*(n-(counts[i]-1))*comas;
                n = counts[i]-1;
            }
        }

        return ans;
    }
};