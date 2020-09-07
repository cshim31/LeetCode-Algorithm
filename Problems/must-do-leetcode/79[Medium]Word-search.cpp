class Solution {
public:
    // point : there exists first letter with surrounding of next letter for sure
    // conclusion : time taken : 34 min failed submission
    // approach was right, but I realized too late that I should've used recursive approach and the problem required path finding algorithm 
    bool exist(vector<vector<char>>& board, string word) {
        int xMax = board.size();
        int yMax = board[0].size();
        
        for(int i = 0; i < xMax; i++) {
            for(int j = 0; j < yMax; j++) {
                // find first letter of the word and perform DFS 
                if(board[i][j] == word[0] && DFS(board, word, 0, i, j)) return true;
            }
        }
        
        return false;
    }
    
    bool DFS(vector<vector<char>>& board, string word, int k, int x, int y) {
        // terminating point
        if(k == word.length()) return true;
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[k]) return false;    
        
        char temp = board[x][y];
        board[x][y] = '*';
        bool search = DFS(board, word, k + 1, x - 1, y) || DFS(board, word, k + 1, x + 1, y) || DFS(board, word, k + 1, x, y + 1) || DFS(board, word, k + 1, x, y - 1);
        board[x][y] = temp;
        return search;
    }
};