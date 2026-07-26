class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        int posFirst = INT_MIN, posSecond = INT_MIN, posThird = INT_MIN;
        int negFirst = INT_MAX, negSecond = INT_MAX, negThird = INT_MAX;

        for(int i : nums){
            if(i > posFirst){
                posThird = posSecond;
                posSecond = posFirst;
                posFirst = i;
            }
            else if(i > posSecond){
                posThird = posSecond;
                posSecond = i;
            }
            else if(i > posThird){
                posThird = i;
            }

            if(negFirst > i){
                negThird = negSecond;
                negSecond = negFirst;
                negFirst = i;
            }
            else if(negSecond > i){
                negThird = negSecond;
                negSecond = i;
            }
            else if(negThird > i){
                negThird = i;
            }
        }


        return max(posFirst*posSecond*posThird, negFirst*negSecond*posFirst);
    }
};