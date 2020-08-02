class Solution {
public:
    // Dynamic Programming
    // top - down method
    int coinChange(vector<int>& coins, int amount) {
        
        int min = compute(coins, amount, new int[amount + 1]());
        return min;
    }
    
    int compute(vector<int>& coins, int amount, int* dp) {
        // not possible
        if(amount < 0) return -1;
        
        // amount divisible by coin
        if(amount == 0) return 0;
        
        //cout << "current amount : " << amount <<endl;
        
        // already evaluated
        if(dp[amount] != 0) {
            return dp[amount];
        }
        
        int numCoin = 0;
        int minCoin = INT_MAX;
        // proceeds top - down
        for(int coin : coins){
            numCoin = compute(coins, amount - coin, dp);
            
            // update to lowest number of coin among the possible coin division
            if(numCoin >= 0) minCoin = min(minCoin, numCoin + 1);
        }
        
        // check whether possible coin division found
        return dp[amount] = (minCoin == INT_MAX)? -1 : minCoin;
    }
};