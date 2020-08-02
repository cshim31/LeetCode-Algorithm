class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> vect;
        for(int i = 0; i < nums.size(); i++) {
            auto it = lower_bound(vect.begin(), vect.end(), nums[i]);
            if(it == vect.end()) vect.push_back(nums[i]);
            else {
                *it = nums[i];
                cout << "incoming : " << *it << endl;
            }
            for(int j = 0; j < vect.size(); j++) cout << vect[j]<<" ";
            cout<<" "<<endl;
        }
        return vect.size();
    }
};