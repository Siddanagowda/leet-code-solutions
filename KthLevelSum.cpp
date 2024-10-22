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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;  // edge case: empty tree
        
        vector<long long> levelSums;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            long long sum = 0;
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            levelSums.push_back(sum);
        }
        
        // Sort sums in descending order
        sort(levelSums.begin(), levelSums.end(), greater<long long>());
        
        // Check if k is within bounds
        if (k > levelSums.size()) return -1;
        
        return levelSums[k - 1];  // return kth largest sum (1-indexed)
    }
};