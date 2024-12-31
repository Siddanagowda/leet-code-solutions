class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        int max_days=days.back();
        vector<int> dp(max_days+1,0);
        int dayIndex=0;
        for(int i=1;i<=max_days;i++){
            if(i!=days[dayIndex]){
                dp[i]=dp[i-1];
            }
            else{
                dp[i]=min(dp[i-1]+costs[0],min(dp[max(i-7,0)]+costs[1],dp[max(i-30,0)]+costs[2]));
                dayIndex++;
            }
        }
        return dp[max_days];
    }
};