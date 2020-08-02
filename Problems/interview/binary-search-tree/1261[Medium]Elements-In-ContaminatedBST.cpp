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
 * Following program computes solution using in - order traversal recursion
 */
class FindElements {
public:
    unordered_set<int> hashset;
    
    FindElements(TreeNode* root) {
        compute(root,0);
    }
    
    void compute(TreeNode* root, int x) {
        if(!root) return;
        
        root->val = x;
        hashset.emplace(x);
        compute(root->left, 2 * x + 1);
        compute(root->right, 2 * x + 2);
    }
    
    bool find(int target) {
        return hashset.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */