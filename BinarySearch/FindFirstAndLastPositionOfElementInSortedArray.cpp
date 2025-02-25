class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> res={-1,-1};
            int i=0;
    
            for(i=0;i<nums.size();i++){
                if(target==nums[i]){
                    if(res[0]==-1){
                        res[0]=i;
                        res[1]=i;
                    }else{
                        res[1]=i;
                    }
                }
            }
            return res;
        }
    };