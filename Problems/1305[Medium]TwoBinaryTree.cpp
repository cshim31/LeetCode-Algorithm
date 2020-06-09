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
    void solve(TreeNode* root, vector<int>& vect) {
        if(!root) return;
        
        solve(root->left,vect);
        solve(root->right,vect);
        
        vect.push_back(root->val);
        return ;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> output;
        solve(root1,output);
        solve(root2,output);
        sort(output.begin(),output.end());
        return output;
    }
};
