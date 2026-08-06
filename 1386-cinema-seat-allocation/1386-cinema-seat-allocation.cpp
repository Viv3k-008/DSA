class Solution {
public:
    int st[3] = {2,4,6};
    int fn(vector<int>& used){
        vector<int> blocked(11, 0);

        // -1 -> blocked

        for(int i : used){   // <= 10
            blocked[i] = -1;
        }

        bool left = true, middle = true, right = true;

        for(int i = 2; i < 2+4; i++){
            if(blocked[i] == -1){
                left = false;
                break;
            }
        }
        for(int i = 4; i < 4+4; i++){
            if(blocked[i] == -1){
                middle = false;
                break;
            }
        }
        for(int i = 6; i < 6+4; i++){
            if(blocked[i] == -1){
                right = false;
                break;
            }
        }

        if(left && right) return 2;
        else if(left || middle || right) return 1;

        return 0;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& blocks) {
        sort(blocks.begin(), blocks.end());


        int ans = 0, st = 1, ed = n;

        for(int i = 0 ; i < blocks.size() ; i++){
            int curRow = blocks[i][0];
            vector<int> used;
            
            ans += (curRow-st)*2;
            st = curRow+1;
            used.push_back(blocks[i][1]);

            bool flag = false;
            while(i+1 < blocks.size() && blocks[i+1][0] == curRow){
                i++;
                used.push_back(blocks[i][1]);
            }

            ans += fn(used);
        }

        ans += (ed-st+1)*2;

        return ans;
    }
};