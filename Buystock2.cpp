class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int profit=0;
        int profit1=0,i;
        for(i=0;i<prices.size()-1;i++){
            if(prices[i]<buy){
                buy=prices[i];
            }
            else if(prices[i]-buy>profit){
                profit=prices[i]-buy;
            }
            if(profit>prices[i+1]-buy){
                profit1+=profit;
                buy=prices[i+1];
                profit=0;
            }
        }
        if(prices[i]-buy>profit||buy!=0){
            profit=prices[i]-buy;
            profit1+=profit;
        }
        return profit1;
    }
};