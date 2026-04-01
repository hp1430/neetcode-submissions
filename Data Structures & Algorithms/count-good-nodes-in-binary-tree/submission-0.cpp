class Solution {
public:
    int preorder(TreeNode *root, int maxi) {
        if(!root) return 0;
        if(root->val >= maxi) return 1+preorder(root->left, max(maxi, root->val)) + preorder(root->right, max(maxi, root->val));
        else return preorder(root->left, max(maxi, root->val)) + preorder(root->right, max(maxi, root->val));
    }
    int goodNodes(TreeNode* root) {
        return preorder(root, INT_MIN);
    }
};
