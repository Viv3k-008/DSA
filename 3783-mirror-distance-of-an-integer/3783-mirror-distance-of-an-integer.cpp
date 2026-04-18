class Solution {
public:
    int mirrorDistance(int n) {
        
        string s = to_string(n);

        reverse(s.begin(),s.end());

        int newNum = stoi(s);

        return abs(n-newNum);
    }
};