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
    bool isValidBST(TreeNode* root) {
        TreeNode* node = NULL;
        return validateBST(root, node);
    }
    
    // function is called on point of every current node
    // in-order traversal
    
    bool validateBST(TreeNode* root, TreeNode* &prev) {
        if(!root) return true;
        
        if(!validateBST(root->left, prev)) return false;
        if(prev != NULL && prev->val >= root->val) return false;
        prev = root;
        return validateBST(root->right, prev);
    }
};