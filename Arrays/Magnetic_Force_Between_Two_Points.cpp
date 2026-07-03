#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// THIS PROBLEM  IS SIMILAR TO AGGRESSIVE COWS PROBLEM

bool canPlace(vector<int>& position, int m, int distance) 
{
    int count = 1;
    int lastPosition = position[0];

    for (int i = 1; i < position.size(); ++i) {
        if (position[i] - lastPosition >= distance) {
            count++;
            lastPosition = position[i];
            if (count == m) return true;
        }
    }
    return false;
}


int maxDistance(vector<int>& position, int m) 
{
    sort(position.begin(), position.end());
    int left = 1;
    int right = position.back() - position.front();
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canPlace(position, m, mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}