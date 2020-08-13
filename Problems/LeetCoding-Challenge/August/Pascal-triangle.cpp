class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 0);
        ans[0] = 1;
        
        int prevNum;
        int currentNum;
        // iterate throu double for loop and compute pascal
        // compute per ith row upto current row
        for(int i = 0; i <= rowIndex; i++) {
            prevNum = ans[0];
            
            for(int j = 1; j <= i; j++) {

                currentNum = ans[j];
                ans[j] += prevNum;
                
                // remember the current index number before addition
                prevNum = currentNum;
            }
        }
        
        return ans;
    }
};