class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // key : anagrams share equal value when strings are sorted
        unordered_map<string, vector<string>> hm;
        
        for(string s : strs) {
            string t = s;
            sort(s.begin(), s.end());
            hm[s].push_back(t);
        }
        
        vector<vector<string>> output;
        for(auto it : hm) {
            output.push_back(it.second);
        }
        
        return output;
    }
};