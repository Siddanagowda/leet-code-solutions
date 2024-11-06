class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int lastGroupMax = INT_MIN;
        int maxi = nums[0];
        int lastBit = __builtin_popcount(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            int bit = __builtin_popcount(nums[i]);
            if (bit == lastBit) {
                maxi = max(maxi, nums[i]);
            } else {
                lastGroupMax = maxi;
                maxi = nums[i];
                lastBit = bit;
            }
            if (nums[i] < lastGroupMax) {
                return false;
            }
        }
        return true;
    }
};