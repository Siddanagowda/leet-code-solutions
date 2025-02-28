class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int s=0,e=0,mini=INT_MAX;
            for(int i=0;i<nums.size();i++){
                e+=nums[i];
                while(e>=target){
                    mini=min(mini,i-s+1);
                    e-=nums[s++];
                }
            }
            return (mini==INT_MAX)?0:mini;
        }
    };