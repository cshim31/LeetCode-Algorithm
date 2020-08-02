class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int i,j;
        int size = grid.size();
        vector<int> topBottom(grid[0].size(),0);
        vector<int> leftRight(grid[0].size(),0);
        
        //find topBottom leftRight
        for(i = 0; i < size; i++) {
            for(j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]>topBottom[i]) topBottom[i]=grid[i][j];
                if (grid[i][j]>leftRight[j]) leftRight[j]=grid[i][j];
            }
        }
        
        int output = 0;
        for(i = 0; i < size; i++) {
            for(j = 0; j < grid[0].size(); j++) {
                int temp = leftRight[i] < topBottom[j]? leftRight[i] : topBottom[j];
                output+=temp - grid[i][j];
                
                cout << output << " ";
            }
        }
        
        return output;
    }
};
