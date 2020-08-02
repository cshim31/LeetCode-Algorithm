class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
       
        unordered_map<int, vector<int>> m;
        int i,j;
        vector<vector<int>> arr;
        for(i = 0; i < groupSizes.size(); i++) {
            m[groupSizes[i]].push_back(i);
            if(m[groupSizes[i]].size() == groupSizes[i]) {
                arr.push_back(m[groupSizes[i]]);
                m[groupSizes[i]] = {};
            }
        }
        
        return arr;
    }
    
};
