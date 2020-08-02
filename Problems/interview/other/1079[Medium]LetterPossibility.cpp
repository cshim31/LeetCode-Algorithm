class Solution {
public:
    void solve(int c[], int& output) {
        int i;
        for(i = 0; i < 26; i++) {
            if(c[i]>0) {
                c[i]--;
                output++;
                solve(c,output);
                c[i]++;
            }
        }
        return ;
    }
    
    int numTilePossibilities(string tiles) {
        int output = 0; int c[26] = {0};
        for(auto i:tiles) {
            c[i-'A']++;
        }
        solve(c,output);
        return output;
    }
};
