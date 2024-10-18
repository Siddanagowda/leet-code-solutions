class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0;
        // Find the maximum OR value of any subset
        for (int num : nums) {
            max_or |= num;
        }
        return solve(0,0,max_or,nums);
    }
    int solve(int i,int cur_or,int max_or,vector<int>& nums){
        if(i>=nums.size()){
            return (cur_or==max_or)?1:0;
        }
        int count=0;
        count+=solve(i+1,cur_or|nums[i],max_or,nums);
        count+=solve(i+1,cur_or,max_or,nums);
        return count;
    }
};
