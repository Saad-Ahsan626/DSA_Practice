#include<iostream>
#include<vector>

using namespace std;

int singleNumber(vector<int>& nums)
{
    int ans = 0;

    for (int value : nums)
    {
        ans = ans ^ value ;
    }

    return ans;
    
}