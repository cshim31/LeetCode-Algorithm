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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> nodesCollection;
        vector<int> rowNodes;
        if(!root) return nodesCollection;
        // perform BFS and search nodes in-order traversal
        queue<TreeNode*> q;
        q.push(root);
        // iterate on each row
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                root = q.front();
                rowNodes.push_back(root->val);
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
                q.pop();
            }
            nodesCollection.push_back(rowNodes);
            rowNodes.resize(0);
        }
        return nodesCollection;
    }
};