class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            vector<int>temp;
            int size=q.size();
            while(size--) {
                TreeNode *tempNode = q.front();
                q.pop();
                if(tempNode->left) q.push(tempNode->left);
                if(tempNode->right) q.push(tempNode->right);
                temp.push_back(tempNode->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
