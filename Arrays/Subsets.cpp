#include<iostream>
#include<vector>

using namespace std;

void generateSubsets(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result)
{
    if (index == nums.size()) 
    {
        result.push_back(current);
        return;
    }

    
    generateSubsets(nums, index + 1, current, result);

    
    current.push_back(nums[index]);
    generateSubsets(nums, index + 1, current, result);
    current.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) // recursive approach
{
    vector<vector<int>> result;
    vector<int> current;
    generateSubsets(nums, 0, current, result);
    return result;
}



vector<vector<int>> subsets(vector<int>& nums) // iterative approach
{
    vector<vector<int>> result;
    int n = nums.size();
    int totalSubsets = 1 << n; 

    for (int i = 0; i < totalSubsets; i++) 
    {
        vector<int> subset;
        for (int j = 0; j < n; j++) 
        {
            if (i & (1 << j)) 
            {
                subset.push_back(nums[j]);
            }
        }
        result.push_back(subset);
    }

    return result;
}