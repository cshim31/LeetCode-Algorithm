class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.length();
        
        // exception
        if(size <= 0) return "";
        if(size <= 1) return s;
        
        // create 2d boolean vector
        // palindromic of substring
        vector<vector<bool>> subStrings(size, vector<bool> (size, false));
        
        // validate default value of words up to length 2
        // basic setting
        for(int i = 0; i < size; i++) {
            // letter itself is palindromic
            subStrings[i][i] = true;
            
            // two letters are substring if and only if they equal
            if(i < size - 1) subStrings[i][i + 1] = s.at(i) == s.at(i + 1);
        }
        
        // dp
        // compare first and last letter
        // compare substring between them
        for(int i = size - 3; i >= 0; i--) {
            for(int j = i + 2; j < size; j++) {
                subStrings[i][j] = subStrings[i + 1][j - 1] && s.at(i) == s.at(j);
            }
        }
        
        
        // look for longest palin
        string longestPalin = "";
        int lengPalin = 0;
        for(int i = 0; i <= size - 2; i++) {
            for(int j = size - 1; j >= i; j--) {
                if(subStrings[i][j] && lengPalin < j - i + 1) {
                    longestPalin = s.substr(i, j - i + 1);
                    lengPalin = j - i + 1;
                }
            }
        }
        return longestPalin;
    }
};