import java.util.Arrays;

class Solution {
    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums);
        long count = 0;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            int leftBoundaryIndex = binarySearch(nums, lower - nums[i], i + 1);
            int rightBoundaryIndex = binarySearch(nums, upper - nums[i] + 1, i + 1);
            count += (rightBoundaryIndex - leftBoundaryIndex);
        }
        return count;
    }
    private int binarySearch(int[] nums, int target, int start) {
        int left = start, right = nums.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}