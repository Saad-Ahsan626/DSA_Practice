#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int findGCD(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int smallest = nums[0];
    int largest = nums[nums.size() - 1];

    
    while (largest != 0) {
        int temp = largest;
        largest = smallest % largest;
        smallest = temp;
    }
    return smallest;
}