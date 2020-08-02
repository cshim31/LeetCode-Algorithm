class Solution {
public:
    // brutal force
    int coinChange(vector<int>& coins, int amount) {
        int min = compute(coins, amount, 0);
        return min;
    }
    
    int compute(vector<int>& coins, int amount, int index) {
        // coin division succeeded
        if(amount <= 0) return 0;
        
        // coin division failed
        if(index >= coins.size()) return -1;

        int minCoin = INT_MAX;
        
        int size = amount / coins[index];
        // proceeds only if amount is divisible by current coin value
        if(amount >= coins[index] * size) {
            int numCoins; 
            // test all amount of coin with coin value, incrementing coin value on next loop
            for(int i = 0; i <= size; i++) {
                numCoins = compute(coins, amount - (coins[index] * i), index + 1);
                
                // succeeded
                if(numCoins >= 0) {
                    numCoins += i;
                    minCoin = min(minCoin, numCoins);
                }
            }
        }
        
        return minCoin == INT_MAX? -1:minCoin;
    }
};