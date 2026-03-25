#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;

        unordered_set<int> set;
        int s = grid.size();

        int a, b;
        int actual_sum = 0, expected_sum = 0;

        for (int i = 0; i < s; i++)
        {
            for (int j = 0; j < s; j++)
            {
                actual_sum += grid[i][j];

                if (set.find(grid[i][j]) != set.end())
                {
                    a = grid[i][j];
                    ans.push_back(a);
                }

                set.insert(grid[i][j]);
                
            }
            
        }

        expected_sum = (s*s) * (s*s + 1) / 2;
        b = expected_sum + a - actual_sum;

        ans.push_back(b);

        return ans;
        
}



