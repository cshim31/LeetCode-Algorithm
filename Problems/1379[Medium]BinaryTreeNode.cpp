/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* temp;
        if(cloned == NULL) return NULL;
        if(cloned->val != target->val) {
            if(cloned->left) temp = getTargetCopy(original,cloned->left,target);
            if(temp != NULL) return temp;
            if(cloned->right) temp = getTargetCopy(original,cloned->right,target);
            if(temp != NULL) return temp;
            return NULL;
        }
        return cloned;
    }
};
