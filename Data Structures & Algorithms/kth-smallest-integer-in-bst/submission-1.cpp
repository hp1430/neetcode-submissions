class Solution {
public:
    int inorder(TreeNode *root, int &k) {
        if(!root) return INT_MIN;
        int lt = inorder(root->left, k);
        if(lt!=INT_MIN) return lt;
        k--;
        if(k==0) return root->val;
        int rt = inorder(root->right, k);
        if(rt!=INT_MIN) return rt;
        return INT_MIN;
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = INT_MIN;
        return inorder(root, k);
    }
};
