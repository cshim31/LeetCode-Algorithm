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
    TreeNode* solve(TreeNode* root, int x) {
        if(!root) {
            root = new TreeNode(x);
            root->left = NULL;
            root->right = NULL;
        }
        
        //Left side
        else if(root->val > x) {
            root->left = solve(root->left,x);
        }
        
        else {
            root->right = solve(root->right,x);
        }
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for(auto x:preorder) {
            root = solve(root,x);
        }
        return root;
    }
};
