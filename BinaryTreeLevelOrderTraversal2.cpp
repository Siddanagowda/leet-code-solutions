/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> level;
        if(!root) return level;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> val;
            for(int i=0;i<n;i++){
                TreeNode* cur=q.front();
                q.pop();
                val.push_back(cur->val);

                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            level.push_back(val);
        }
        reverse(level.begin(),level.end());
        return level;
    }
};