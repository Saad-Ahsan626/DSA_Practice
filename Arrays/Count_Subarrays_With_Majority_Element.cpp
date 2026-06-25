#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int countMajoritySubarrays(vector<int>& nums, int target) 
{
    int n = nums.size();
    
    
    unordered_map<int, int> freq;
    freq[0] = 1; 
    
    int current_sum = 0;
    int count = 0;
    int valid_subarrays = 0; 
    
    for (int num : nums) {
        
        int val = (num == target) ? 1 : -1;
        current_sum += val;
        
        
        if (val == 1) {
            
            valid_subarrays += freq[current_sum - 1];
        } else {
          
            valid_subarrays -= freq[current_sum];
        }
        
        count += valid_subarrays;
        freq[current_sum]++;
    }
    
    return count;
}