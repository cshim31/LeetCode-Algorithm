class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int a = 0;
        int b = matrix.size() - 1;
        
        // looped every outbound swap
        while(b > a) {
            // swap only half of matrix
            for(int i = 0; i < b - a; i++) {
                swap(matrix[a][a + i], matrix[a + i][b]);
                swap(matrix[a][a + i], matrix[b][b - i]);
                swap(matrix[a][a + i], matrix[b - i][a]);
            }
            ++a;
            --b;
        }
    }
};