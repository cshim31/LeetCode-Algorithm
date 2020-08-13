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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzagTraversal;
        
        if(!root) return zigzagTraversal;
        
        bool leftToRight = true;
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        
        while(!treeQueue.empty()) {
            int size = treeQueue.size();
            vector<int> temp(size);
            
            for(int i = 0; i < size; i++) {
                TreeNode* node = treeQueue.front();
                treeQueue.pop();
                
                if(leftToRight) {
                    temp[i] = node->val;
                } 
                if(!leftToRight) {
                    temp[size - 1 - i] = node->val;
                }
                
                // add next tree nodes
                if(node->left) treeQueue.push(node->left);
                if(node->right) treeQueue.push(node->right);
            }
            
            leftToRight = !leftToRight;
            zigzagTraversal.push_back(temp);
        }
        
        return zigzagTraversal;
    }
};