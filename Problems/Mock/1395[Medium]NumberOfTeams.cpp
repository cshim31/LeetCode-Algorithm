class Solution {
public:
    int numTeams(vector<int>& rating) {
        int i,j,k;
        int output = 0;
        
        for(i = 0; i < rating.size() - 2; i++) {
            for(j = i+1; j < rating.size() - 1;j++) {
                for(k = j+1; k < rating.size(); k++) {
                    if(rating[i] < rating[j] && rating[j] < rating[k]) output++;
                    else if(rating[i] > rating[j] && rating[j] > rating[k]) output++;
                }
            }
        }
        
        return output;
    }
};
