//700. Search in a Binary Search Tree
//https://leetcode.com/problems/search-in-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    
    while (root && root->val != val){
        if (root->val > val)
            root = root->left;
        else
            root = root->right;
    }

    return root;

}