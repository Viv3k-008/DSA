class Solution {
public:
    int fn(string& current){

        int hr = (current[0]-'0')*10 + current[1]-'0';
        int min = (current[3]-'0')*10 + current[4]-'0';

        int totalMins = (hr*60)+min;

        return totalMins;
    }
    int convertTime(string current, string correct) {

        int totalMins = fn(correct)-fn(current);
        

        int inc[4] = {1, 5, 15, 60};

        int steps = 0;
        for(int i = 3; i >= 0 ; i--){
            steps += totalMins/inc[i];
            totalMins = totalMins%inc[i];
        }

        return steps;
    }
};