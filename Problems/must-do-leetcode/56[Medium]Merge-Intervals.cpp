point : 이전 벡터의 first second 범주안에만 든다면 확실

class Solution {
public:
    // point : in incrementing order, as long as next vector is in range of first second of current vector,
   // it is guranteed to have extended vector
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> output;
        if(intervals.size() <= 0) return output;
        
        sort(intervals.begin(), intervals.end());
        
        output.push_back(intervals[0]);
        
        vector<int> temp;
        for(int i = 1; i < intervals.size(); i++) {
            temp = output.back();
            
            if(temp[0] <= intervals[i][0] && temp[1] >= intervals[i][0]) {
                temp[0] = min(temp[0], intervals[i][0]);
                temp[1] = max(temp[1], intervals[i][1]);
                output.pop_back();
                output.push_back(temp);
            }
            else {
                output.push_back(intervals[i]);
            }
        }
        
        return output;
    }
};