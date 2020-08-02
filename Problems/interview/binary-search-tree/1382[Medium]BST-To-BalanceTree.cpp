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

/*
 * Approach : Store elements of each node and rebuild a BST structure using merging sort algorithm
 */
class Solution {
public:
    void storeBST(TreeNode* root, vector<TreeNode*> &vect) {
        if(!root) return;
        storeBST(root->left,vect);
        vect.push_back(root);
        storeBST(root->right,vect);
        return;
    }
    
    TreeNode* balanceBSTUtill(vector<TreeNode*> &vect, int n, int m) {
        if(n > m) return nullptr;
        
        int mid = (n + m) / 2;
        TreeNode* root = vect[mid];
        root->left = balanceBSTUtill(vect, n, mid - 1);
        root->right = balanceBSTUtill(vect, mid + 1, m);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> vect;
        storeBST(root, vect);
        
        int size = vect.size();
        root = balanceBSTUtill(vect, 0, size - 1);
        return root;
    }
};