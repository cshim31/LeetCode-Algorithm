class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        unordered_map<int,int> p;
        vector<int> output;
        
        int i,j;
        //map pair(value,index)
        for(i = 0; i <m; i++) p[i + 1] = i;
        for(i = 0; i < queries.size(); i++) {
            int val = queries[i];
            int index = p[val];
            output.push_back(index);
            
            for(auto &it:p) {
                if(it.second < index)
                it.second++;
            }
            
            p[val] = 0;
            
        }
        return output;
    }
};
