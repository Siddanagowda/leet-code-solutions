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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> avg;
        if(!root) return avg;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int l=q.size();
            double levelsum=0.0;
            for(int i=0;i<l;i++){
                TreeNode* cur=q.front();
                q.pop();
                levelsum+=cur->val;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            avg.push_back(levelsum/l);
        }
        return avg;
    }
};