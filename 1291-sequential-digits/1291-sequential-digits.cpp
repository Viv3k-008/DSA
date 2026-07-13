class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        string s = to_string(low);
        string e = to_string(high);

        int n = s.size(), m = e.size();
        bool done = false;

        for(int i = n ; i <= m ; i++){
            char ed = (10-i)+'0';
            for(char c = '1' ; c <= ed ; c++){
                string temp = "";
                char ch = c;
                for(int len = 0 ; len < i ; len++){
                    temp += ch;
                    ch += 1;
                }

                int num = stoi(temp);
                if(num >= low && num <= high) ans.push_back(num);
                if(num > high){
                    done = true;
                    break;
                }
            }
            if(done) break;
        }


        return ans;
    }
};