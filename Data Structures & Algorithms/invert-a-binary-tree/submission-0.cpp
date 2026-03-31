class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode *lt = root->left;
        TreeNode *rt = root->right;
        root->left=rt;
        root->right=lt;
        if(root->left) invertTree(root->left);
        if(root->right) invertTree(root->right);
        return root;
    }
};
