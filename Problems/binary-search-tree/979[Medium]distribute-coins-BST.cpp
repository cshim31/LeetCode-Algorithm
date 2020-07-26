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
    int output = 0;
    int distributeCoins(TreeNode* root) {
        int coin = 0;
        run(root, coin);
        
        return coin;
    }
    
    int run(TreeNode* root, int& coin) {
        if(!root) return 0;
        
        // leftcoins and rightcoins indicate numer of coins transferred from each side
        int leftCoins = run(root->left, coin);
        int rightCoins = run(root->right, coin);
        
        coin += abs(leftCoins) + abs(rightCoins);
        
        // keep one coin for current node
        // return number of coin to be passed to head node
        return root->val - 1 + leftCoins + rightCoins;
            
    }
};