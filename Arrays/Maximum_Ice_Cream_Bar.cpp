#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxIceCream(vector<int>& costs, int coins) 
{
    int count = 0;
    sort(costs.begin(), costs.end());

    for (int cost : costs) 
    {
        if (cost <= coins) 
        {
            coins -= cost;
            count++;
        } 
        else 
        {
            break;
        }
    }

    return count;
}