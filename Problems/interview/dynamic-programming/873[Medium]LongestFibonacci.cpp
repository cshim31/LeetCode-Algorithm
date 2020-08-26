class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int length = A.size();
        unordered_set<int> dp(A.begin(), A.end());
        
        int longestFib = 0;
        for(int i = 0; i < length; i++) {
            for(int j = i + 1; j < length; j++) {
                
                // fibonacci exists
                int a = A[i];
                int b = A[j];
                int l = 2;
                while(dp.count(a + b)) {
                    b = a + b;
                    a = b - a;
                    l++;
                }
                
                longestFib = max(longestFib, l);
            }
        }
        
        return longestFib == 2? 0 : longestFib;
    }
};