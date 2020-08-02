class Solution {
public:
    priority_queue<int> pq;
    int solve(vector<vector<int>>& mat, int i, int j) {
        if(i < 0 || j < 0) return -1;
        
        pq.push(solve(mat,i-1,j-1));
        return mat[i][j];
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int i,j;
        
        i = mat.size() - 1;
        j = 0;
        int range = mat[0].size() + mat.size() - 1;
        while(j < range) {
            int x = i;
            int y = j;
            
            //pq contains sorted diagonal matrix value
            while(y >= mat[0].size()) {
                x--;
                y--;
            }
            pq.push(solve(mat,x,y));
            
            
            while(pq.top() >= 1) {
                mat[x][y] = pq.top();
                pq.pop();
                y--;
                x--;
            }
            j++;
        }
        
        return mat;
    }
};
