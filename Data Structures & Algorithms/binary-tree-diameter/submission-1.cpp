class Solution {
public:
    int diameter = 0;
    int height(TreeNode *root) {
        if(!root) return 0;
        int lt = height(root->left);
        int rt = height(root->right);
        diameter = max(diameter, lt+rt);
        return 1+max(lt, rt);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};