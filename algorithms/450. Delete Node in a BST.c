//450. Delete Node in a BST
//https://leetcode.com/problems/delete-node-in-a-bst/

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (!root) return NULL;
    
    struct TreeNode dummy;
    dummy.left = root;
    
    struct TreeNode* parent = &dummy;
    struct TreeNode* curr = root;
    
    // Find the node to delete and its parent
    while (curr && curr->val != key) {
        parent = curr;
        if (key > curr->val) {
            curr = curr->right;
        } else {
            curr = curr->left;  
        }
    }
    

    if (!curr) return root;
    
    // handle deletion based on child count
    if (!curr->left) {
        // Node has only right child or no children
        if (parent->left == curr) {
            parent->left = curr->right;
        } else {
            parent->right = curr->right;
        }
        free(curr);  // FIXED: Free the deleted node
    } else if (!curr->right) {
        // Node has only left child
        if (parent->left == curr) {
            parent->left = curr->left;
        } else {
            parent->right = curr->left;
        }
        free(curr);  
    } else {
        // Node has two children
        struct TreeNode* inorderSucc = curr->right;
        struct TreeNode* inorderSuccParent = curr;
        
        while (inorderSucc->left) {
            inorderSuccParent = inorderSucc;
            inorderSucc = inorderSucc->left;
        }
        
        curr->val = inorderSucc->val;
        

        if (inorderSuccParent == curr) {
            inorderSuccParent->right = inorderSucc->right;
        } else {
            inorderSuccParent->left = inorderSucc->right;
        }
        
        free(inorderSucc);
    }
    
    return dummy.left;  
}