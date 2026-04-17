#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices) {
     
    int max_profit = 0;
    int best_buy_price = prices[0];

    for (int i = 1; i < prices.size(); i++) 
    {
        if (prices[i] < best_buy_price) 
        {
            best_buy_price = prices[i];
        } 
        else 
        {
            max_profit = max(max_profit, prices[i] - best_buy_price);
        }
    }
    return max_profit;
}