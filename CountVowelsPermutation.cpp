class Solution {
public:
    int countVowelPermutation(int n) {
        int mod=1e9+7;
        vector<long> dp(5,1);
        vector<long> prev(5);

        for(int i=2;i<=n;i++){
            prev=dp;
            dp[0]=prev[1]%mod;
            dp[1]=prev[0]+prev[2]%mod;
            dp[2]=prev[0]+prev[1]+prev[3]+prev[4]%mod;
            dp[3]=prev[2]+prev[4]%mod;
            dp[4]=prev[0]%mod;
        }
        return (dp[0]+dp[1]+dp[2]+dp[3]+dp[4])%mod;
    }
};