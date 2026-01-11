class Solution {
public:
    int fn(vector<int>& arr){
        int n = arr.size();
        stack<int> stk;
        vector<int> pSmall(n);
        vector<int> nSmall(n);

        for(int i = 0 ; i < n ; i++){

            while(!stk.empty() && arr[stk.top()] >= arr[i]) stk.pop();

            pSmall[i] = stk.empty() == true ? -1 : stk.top();
            stk.push(i); 
        }
        
        while(!stk.empty()) stk.pop();
        
        for(int i = n-1 ; i >= 0 ; i--){

            while(!stk.empty() && arr[stk.top()] >= arr[i]) stk.pop();

            nSmall[i] = stk.empty() == true ? n : stk.top();
            stk.push(i);
        }

        int maxi = INT_MIN;

        for(int i = 0 ; i < n ; i++){

            maxi = max(maxi , (nSmall[i]-pSmall[i]-1)*arr[i]);
        }

        return maxi;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix[0].size();
        int maxi = INT_MIN;
        vector<int> prev(n , 0) , cur(n , 0);

        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < n ; j++){
                
                if(matrix[i][j] != '0') cur[j] = (matrix[i][j] - '0') + prev[j];
                else cur[j] = 0;
                
            }
            maxi = max(maxi , fn(cur));
            prev = cur;
        }

        return maxi;
    }
};