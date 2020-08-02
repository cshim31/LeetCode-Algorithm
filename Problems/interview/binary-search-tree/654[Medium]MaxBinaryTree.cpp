/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
       return construct(nums,0,nums.size() - 1);
    }
    
    TreeNode* construct(vector<int>& nums, int l, int r) {
        if(l == r) return new TreeNode(nums[l]);
        if(l > r) return NULL;
        int index = findMax(nums,l,r);
        TreeNode* root = new TreeNode(nums[index]);
        root->left = construct(nums, l, index - 1);
        root->right = construct(nums,index+1,r);
        return root;
    }
    
    int findMax(vector<int>& nums, int l, int r) {
        int index = 0, max = 0;
        
        for(int i = l; i <= r; i++) {
            if(max < nums[i]) {
                max = nums[i];
                index = i;
            }
        }
        
        return index;
    }
};
