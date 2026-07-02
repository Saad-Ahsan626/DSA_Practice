#include<iostream>
#include<vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    int m = matrix.size();
    if (m == 0) return {};
    
    int n = matrix[0].size();

    vector<int> result;
    int startRow = 0, endRow = m - 1;
    int startCol = 0, endCol = n - 1;

    while (startRow <= endRow && startCol <= endCol)
    {
        
        for (int col = startCol; col <= endCol; ++col)
            result.push_back(matrix[startRow][col]);
        startRow++;

        
        for (int row = startRow; row <= endRow; ++row)
            result.push_back(matrix[row][endCol]);
        endCol--;

        
        if (startRow <= endRow) 
        {
            for (int col = endCol; col >= startCol; --col)
                result.push_back(matrix[endRow][col]);
            endRow--;
        }

        
        if (startCol <= endCol) 
        {
            for (int row = endRow; row >= startRow; --row)
                result.push_back(matrix[row][startCol]);
            startCol++;
        }
    }

    return result;
}