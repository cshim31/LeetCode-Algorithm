class Solution {
public:
    // point : one digit in range (0<x<9) always exists that adds output
    //          two digit in range (10<=x<=26) always exists that adds output
    int numDecodings(string s) {
        int size = s.length();
        if(size < 1 || s[0] == '0') return 0;
        
        vector<int> dp(size + 1);
        dp[0] = 1;
        
        for(int i = 1; i <= size; i++) {
            if(s[i] == '0') dp[i] = 0;
            else {
                // one digit sum
                dp[i] = dp[i - 1];
                // two digit sum
                if(i - 2 >= 0 && (s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] <= '6')) dp[i] += dp[i - 2];
            }
        }
        
        return dp[size];
    }
};