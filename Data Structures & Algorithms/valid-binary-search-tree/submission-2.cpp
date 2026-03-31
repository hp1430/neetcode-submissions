class Solution {
public:
    int prev = INT_MIN;
    bool inorder(TreeNode *root) {
        if(!root) return true;
        if(!inorder(root->left)) return false;;
        if(root->val<=prev) return false;
        prev=root->val;
        if(!inorder(root->right)) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
};
