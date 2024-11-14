public class Solution {
    public int minimizedMaximum(int n, int[] quantities) {
        int left = 1;
        int right = Arrays.stream(quantities).max().getAsInt();
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDistributeWithMaxX(mid, n, quantities)) {
                result = mid; 
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }

    private boolean canDistributeWithMaxX(int x, int n, int[] quantities) {
        int storesNeeded = 0;
        for (int quantity : quantities) {
            storesNeeded += (int) Math.ceil((double) quantity / x);
            if (storesNeeded > n) { 
                return false;
            }
        }
        return storesNeeded <= n;
    }
}
