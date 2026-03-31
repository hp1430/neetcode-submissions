class Solution {
public:
    int level(TreeNode *root) {
        if(!root) return 0;
        return 1+max(level(root->left), level(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int lt = level(root->left);
        int rt = level(root->right);
        int diameter = lt+rt;
        return max({diameter, diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)});
    }
};