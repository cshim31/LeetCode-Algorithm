class Solution {
public:
    int kthFactor(int n, int k) {
        map<int, int> m;
        int index = 0;
        
        for(int i = 1; i <= n; i++) {
            if(n % i == 0) {
                m[index] = i;
                index++;
            }
        }
        
        if(k == 0) return m[0];
        
        return k <= m.size()? m[k - 1] : -1;
    }
};