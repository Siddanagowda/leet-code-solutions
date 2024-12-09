class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> pair(n);
        for(int i=0;i<n;i++){
            pair[i]=nums[i]%2;//even 0 odd 1
        }
        vector<int> bad(n-1,0);
        for(int i=0;i<n-1;i++){
            if(pair[i]==pair[i+1]){
                bad[i]=1;
            }
        }
        vector<int> bad_prefix(n,0);
        for(int i=1;i<n;i++){
            bad_prefix[i]=bad_prefix[i-1]+bad[i-1];
        }
        vector<bool> res;
        for(auto& query:queries){
            int fromi=query[0];
            int toi=query[1];
            if(bad_prefix[toi]-bad_prefix[fromi]==0){
                res.push_back(true);
            }
            else{
                res.push_back(false);
            }
        }
        return res;
    }
};