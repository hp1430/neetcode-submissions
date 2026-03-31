class Solution {
public:
    int check(TreeNode *root) {
        if(!root) return 0;
        int lt = check(root->left);
        if(lt==-1) return -1;
        int rt = check(root->right);
        if(rt==-1) return -1;
        if(abs(lt-rt)>1) return -1;
        return 1+max(lt, rt);
    }
    bool isBalanced(TreeNode* root) {
        return check(root)!=-1;
    }
};
