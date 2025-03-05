class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            // vector<vector<int>> res;
            // int l=0,r=2,m=0;
            // int sum=0;
            // for(int i=0;i<nums.size();i++){
            //     for(int j=i+1;j<nums.size();j++){
            //         for(int k=j+1;k<nums.size();k++){
            //             vector<int> v1;
            //             int s=nums[i]+nums[j]+nums[k];
            //             if(s==sum){
            //                 v1.push_back(nums[i]);
            //                 v1.push_back(nums[j]);
            //                 v1.push_back(nums[k]);
            //                 // for(int a : v1){
            //                 //     cout<<a<<"\t";
            //                 // }cout<<"\n";
            //                 sort(v1.begin(),v1.end());
            //                 bool flag=false;
            //                 for(const auto& a: res){
            //                     if(a==v1){
            //                         flag=true;
            //                         break;
            //                     }
            //                 }
            //                 if(!flag)
            //                     res.push_back(v1);
            //             }
            //         }
            //     }
            // }
            // return res;
    
            vector<vector<int>> result;
            sort(nums.begin(),nums.end());
            for (int i = 0; i < nums.size() - 2; ++i) {
                if (i > 0 && nums[i] == nums[i - 1]) {
                    continue;
                }
                int target = -nums[i];
                int left = i + 1, right = nums.size() - 1;
                while (left < right) {
                    int current_sum = nums[left] + nums[right];
                    if (current_sum == target) {
                        result.push_back({nums[i], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) {
                            ++left;
                        }
                        while (left < right && nums[right] == nums[right - 1]) {
                            --right;
                        }
                        ++left;
                        --right;
                    } else if (current_sum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
            return result;
        }
    };