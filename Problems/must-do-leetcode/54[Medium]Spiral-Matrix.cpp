class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> output;
        vector<vector<int>> temp = matrix;
        // exception
        if(matrix.size() == 0 || matrix[0].size() == 0) return output;
        
        // pop top line of matrix and rotate
        while(true) {
            for(int i = 0; i < temp[0].size(); i++) output.push_back(temp[0][i]);
            temp.erase(temp.begin());
            if(temp.empty()) break;
            temp = rotateVector(temp);
        }
        
        return output;
    }
    
    vector<vector<int>> rotateVector(vector<vector<int>> matrix) {
        int xSize = matrix.size();
        int ySize = matrix[0].size();
        if(xSize == 1 && ySize == 1) return matrix;
        vector<vector<int>> output(ySize, vector<int>(xSize));
        
        for(int i = 0; i < ySize; i++)
            for(int j = 0; j < xSize; j++) {
                output[i][j] = matrix[j][ySize - i - 1];
            }
        matrix.clear();
        return output;
    }
};