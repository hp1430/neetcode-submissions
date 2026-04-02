class Solution {
public:
    TreeNode *helper(vector<int>&preorder, vector<int>&inorder, int prelo, int prehi, int inlo, int inhi) {
        if(prehi<prelo) return NULL;
        TreeNode *root = new TreeNode(preorder[prelo]);
        if(prelo==prehi) return root;
        int i;
        for(i=inlo; i<=inhi; i++) if(inorder[i]==preorder[prelo]) break;
        int lCount = i-inlo;
        int rCount = inhi-lCount;
        root->left = helper(preorder, inorder, prelo+1, prelo+lCount, inlo, i-1);
        root->right = helper(preorder, inorder, prelo+1+lCount, prehi, i+1, inhi);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return helper(preorder, inorder, 0, n-1, 0, n-1);
    }
};
