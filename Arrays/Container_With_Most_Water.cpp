#include<iostream>
#include<vector>

using namespace std;

int maxArea(vector<int>& height) 
{
    int maxArea = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left < right) {
        int w = right - left;
        int h = min(height[left], height[right]);
        int currentArea = w * h;
        maxArea = max(maxArea, currentArea);

        if (height[left] < height[right]) 
        {
            left++;
        } else 
        {
            right--;
        }
    }

    return maxArea;
}