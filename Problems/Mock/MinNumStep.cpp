class Solution {
public:
    int minSteps(string s, string t) {
     
        unordered_map<char,int> hashmap;
        int output = 0;
    
        for(auto i:s) hashmap[i]++;
        for(auto i:t) hashmap[i]--;
        for(auto i:hashmap) {
            if(i.second)
        }
        return output;
    }
};
