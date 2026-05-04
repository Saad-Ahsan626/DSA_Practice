#include<iostream>
#include<vector>

using namespace std;

void sortColors(vector<int>& nums) 
{
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high) 
    {
        if (nums[mid] == 0) 
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } 
        else if (nums[mid] == 1) 
        {
            mid++;
        } 
        else 
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }        
}

void sortColors(vector<int>& nums) 
{
    int count0 = 0, count1 = 0, count2 = 0;

    for (int num : nums) 
    {
        if (num == 0) 
        {
            count0++;
        } 
        else if (num == 1) 
        {
            count1++;
        } 
        else 
        {
            count2++;
        }
    }

    int index = 0;
    for (int i = 0; i < count0; i++) 
    {
        nums[index++] = 0;
    }
    for (int i = 0; i < count1; i++) 
    {
        nums[index++] = 1;
    }
    for (int i = 0; i < count2; i++) 
    {
        nums[index++] = 2;
    }
}