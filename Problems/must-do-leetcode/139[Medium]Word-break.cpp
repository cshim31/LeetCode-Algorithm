class Solution {
public:
    // point : problem solvable by brute force for sure
    // improve performance by using dynamic programming
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hs(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1, 0);
        dp[0] = true;
        for(int i = 1; i <= s.length(); i++) {
            for(int j = i - 1; j >= 0; j--) {
                
                if(dp[j]){
                    string b = s.substr(j, i - j);
                    // word exists in dictionary
                    if(hs.count(b) >= 1) {
                        dp[i] = true; 
                        break; 
                    } 
                }
            }
        }
        return dp[s.length()];
    }
};