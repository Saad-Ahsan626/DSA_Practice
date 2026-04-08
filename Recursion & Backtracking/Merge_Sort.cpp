#include<iostream>
#include<vector>

using namespace std;

vector<int> sortArray(vector<int>& nums) {
    if (nums.size() <= 1) return nums;

    int mid = nums.size() / 2;
    vector<int> left(nums.begin(), nums.begin() + mid);
    vector<int> right(nums.begin() + mid, nums.end());

    left = sortArray(left);
    right = sortArray(right);

    return merge(left, right);
}

vector<int> merge(vector<int>& left, vector<int>& right) {
    vector<int> merged;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            merged.push_back(left[i]);
            i++;
        } else {
            merged.push_back(right[j]);
            j++;
        }
    }

    
    merged.insert(merged.end(), left.begin() + i, left.end());
    merged.insert(merged.end(), right.begin() + j, right.end());

    return merged;
}