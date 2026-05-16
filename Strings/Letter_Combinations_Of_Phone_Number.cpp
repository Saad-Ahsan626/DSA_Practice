#include<iostream>
#include<vector>

using namespace std;

vector<string> letterCombinations(string digits) 
{
    vector<string> result;
    if(digits.empty())
        return result;
    
    vector<string> mapping = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    result.push_back("");
    
    for(char digit : digits)
    {
        vector<string> temp;
        string letters = mapping[digit - '0'];
        
        for(string combination : result)
        {
            for(char letter : letters)
            {
                temp.push_back(combination + letter);
            }
        }
        
        result = temp;
    }
    
    return result;        
}