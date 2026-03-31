class Solution {
public:
    void inorder(TreeNode *root, vector<int>&nums) {
        if(!root) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    bool isValidBST(TreeNode* root) {
        vector<int>nums;
        inorder(root, nums);
        for(int i=1; i<nums.size(); i++) if(nums[i]<=nums[i-1]) return false;
        return true;
    }
};
