class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k) return 0;

        unordered_map<int, int> freq;
        int left = 0;
        long long current_sum = 0;
        long long max_sum = 0;

        for (int right = 0; right < n; ++right) {
            freq[nums[right]]++;
            current_sum += nums[right];

            while (freq[nums[right]] > 1) {
                freq[nums[left]]--;
                current_sum -= nums[left];
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++; 
            }
            if ((right - left + 1) == k) {
                max_sum = max(max_sum, current_sum);
                freq[nums[left]]--;
                current_sum -= nums[left];
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++; 
            }
        }
        return max_sum; 
    }
};
