class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> solution;
        vector<int> backTracking;
        int index = 0;
        solve(candidates, target, solution, backTracking, index);
        return solution;
    }
    
    void solve(vector<int>& candidates, int target, vector<vector<int>>& solution, vector<int>& backTracking, int index) {
        if(target == 0) {
            solution.push_back(backTracking);
            return ;
        }
        for(int i = index; i < candidates.size(); i++){
            if(target < candidates[i]) continue;
            backTracking.push_back(candidates[i]);
            solve(candidates, target - candidates[i], solution, backTracking, i);
            backTracking.pop_back();
        }
    }
};