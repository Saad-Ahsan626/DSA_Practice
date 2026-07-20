#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) 
{
    
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> result(m, vector<int>(n));
    
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            int newPos = (i * n + j + k) % (m * n);
            result[newPos / n][newPos % n] = grid[i][j];
        }
    }
    
    return result;        
}