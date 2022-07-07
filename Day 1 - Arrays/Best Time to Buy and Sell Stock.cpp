int maximumProfit(vector<int> &prices){
    int mx = prices.back();
    int profit = 0;
    
    for(int i=prices.size()-2; i>=0; i--){
        mx = max(mx, prices[i]);
        profit = max(profit, mx - prices[i]);
    }
    return profit;
}