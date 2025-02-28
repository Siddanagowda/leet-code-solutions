class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
            int index=0;
            int x=nums[0];
            for(int i=1;i<nums.size();i++){
                if(nums[i]>x){
                    index=i;
                    x=nums[i];
                }
            }
            return index;
        }
    };