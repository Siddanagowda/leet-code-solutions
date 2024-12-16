class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for(int i=0;i<k;i++){
            int x=*min_element(nums.begin(),nums.end());
            auto index=find(nums.begin(),nums.end(),x);
            x=x*multiplier;
            nums[index-nums.begin()]=x;
        }
        return nums;
    }
};