class Solution {
public:
    // point : max product guranteed as long as one negative and zero avoided
    //          because product always bring greater amount when multiplied by positive integer or two negative integer
    // Missed Point : 1) if odd number of negative integer exists, it is guranteed to have maximum integer 
    //              : on the right hand (i + 1 from negative index) or on the left hand(i - 1 from negative index)
    //              : 2)if even number of negative integer exists, it is guranteed to have maximum integer on both hand
    // 해야했던것    : 1) I should've used "always true" fact and thought ahead
    //                  rather than thinking that odd number of negative should be "avoided", I should've thought max product is calculated on the other hand
    //              because unlike zero, one negative integer is possible to cause to answer
    int maxProduct(vector<int> A) {
        int n = A.size(), res = A[0], l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            l =  (l ? l : 1) * A[i];
            r =  (r ? r : 1) * A[n - 1 - i];
            res = max(res, max(l, r));
        }
        return res;
    }
};