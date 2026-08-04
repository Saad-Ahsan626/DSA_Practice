#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

vector<int> findMissingElements(vector<int>& nums) 
{
    sort(nums.begin(), nums.end());
    vector<int> result;
        
    for (size_t i = 0; i < nums.size() - 1; ++i) 
    {
        for (int val = nums[i] + 1; val < nums[i + 1]; ++val) 
        {
            result.push_back(val);
        }
    }
        
    return result;
    
}