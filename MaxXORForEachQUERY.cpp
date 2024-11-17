class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int maxValue = (1 << maximumBit) - 1;
        vector<int> results;
        int n=nums.size(),cur=0; 
        for (int i=0;i<n;i++) {
            cur^=nums[i];
            results.push_back(cur ^ maxValue); 
        }
        reverse(results.begin(), results.end());
        return results;
    }
};