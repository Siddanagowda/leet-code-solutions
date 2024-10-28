class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> set(nums.begin(),nums.end());
        int maxlen=0;
        for(int num:nums){
            unsigned long long cur=num;
            int len=0;
            while(set.find(cur)!=set.end()){
                len++;
                cur*=cur;
                if (cur > INT_MAX) break;
            }
            if(len>1)
                maxlen=max(maxlen,len);
        }
        return maxlen>1?maxlen:-1;
    }
};