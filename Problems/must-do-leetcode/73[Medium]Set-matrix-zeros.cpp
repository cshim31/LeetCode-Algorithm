class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // scan 0 from last elements
        int lastZero = -1;
        for(int i = m - 1; i >= 0 && lastZero == -1; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(matrix[i][j] == 0) {
                    lastZero = i;
                    break;
                }
            }
        }
        // early termination
        if(lastZero < 0) return ;
        
        // save zero's in last row
        bool isRowZero = false;
        for(int i = 0; i < lastZero; i++) {
            isRowZero = false;
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    isRowZero = true;
                    matrix[lastZero][j] = 0;
                }
            }
            
            if(isRowZero) {
                for(int j = 0; j < n; j++) matrix[i][j] = 0;
            }
        }
        
        // recall saved zeros in last row and set column zero
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                matrix[i][j] = matrix[lastZero][j] == 0? 0 : matrix[i][j];
            }
        }
        
        // set zeros in last row
        for(int j = 0; j < n; j++) {
            matrix[lastZero][j] = 0;
        }
    }
};