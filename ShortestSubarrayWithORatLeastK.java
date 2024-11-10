// this code is correct but for larger input the constraint for time will exceeds 
// class Solution {
//     public int minimumSubarrayLength(int[] nums, int k) {
//         int n=nums.length;
//         int cur_or=0;
//         int start=0;
//         int min_len=Integer.MAX_VALUE;

//         for(int end=0;end<n;end++){
//             cur_or |=nums[end];
//             while(cur_or>=k){
//                 min_len=Math.min(min_len,end-start+1);
//                 start++;
//                 if(start<=end){
//                     cur_or=recalculate(nums,start,end);
//                 }
//                 else{
//                     break;
//                 }
//             }
//         }
//         return min_len!=Integer.MAX_VALUE ? min_len:-1;
//     }
//     private int recalculate(int[] nums,int start,int end){
//         int or_val=0;
//         for(int i=start;i<=end;i++){
//             or_val |=nums[i];
//         }
//         return or_val;
//     }
// }

import java.util.*;

class Solution {
    public int minimumSubarrayLength(int[] nums, int k) {
        int n = nums.length;
        int[] bitCount = new int[32];  
        int currentOR = 0;
        int left = 0;
        int minLength = Integer.MAX_VALUE;

        for (int right = 0; right < n; right++) {
            currentOR |= nums[right];  

            for (int bit = 0; bit < 32; bit++) {
                if ((nums[right] & (1 << bit)) != 0) {
                    bitCount[bit]++;
                }
            }
            while (left <= right && currentOR >= k) {
                minLength = Math.min(minLength, right - left + 1);

                int updatedOR = 0;
                for (int bit = 0; bit < 32; bit++) {
                    if ((nums[left] & (1 << bit)) != 0) {
                        bitCount[bit]--;
                    }
                    if (bitCount[bit] > 0) {
                        updatedOR |= (1 << bit);
                    }
                }
                currentOR = updatedOR;  
                left++;
            }
        }
        return minLength == Integer.MAX_VALUE ? -1 : minLength;
    }
}
