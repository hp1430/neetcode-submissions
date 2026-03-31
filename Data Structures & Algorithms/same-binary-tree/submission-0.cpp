class Solution {
public:
    void inOrder(TreeNode *root, vector<int>&nums) {
        if(!root) {
            nums.push_back(INT_MIN);
            return;
        };
        nums.push_back(root->val);
        inOrder(root->left, nums);
        inOrder(root->right, nums);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>pInOrder, qInOrder;
        inOrder(p, pInOrder);
        inOrder(q, qInOrder);
        for(int i=0; i<pInOrder.size(); i++) {
            if(i>=qInOrder.size()) return false;
            if(pInOrder[i]!=qInOrder[i]) return false;
        }
        return true;
    }
};
