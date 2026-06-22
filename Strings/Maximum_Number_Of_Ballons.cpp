#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<climits>

using namespace std;

int maxNumberOfBalloons(string text) 
{
    unordered_map<char, int> charCount;
    
    for (char c : text) 
    {
        charCount[c]++;
    }
    
    int countBalloons = INT_MAX;
    
    countBalloons = min(countBalloons, charCount['b']);
    countBalloons = min(countBalloons, charCount['a']);
    countBalloons = min(countBalloons, charCount['l'] / 2);
    countBalloons = min(countBalloons, charCount['o'] / 2);
    countBalloons = min(countBalloons, charCount['n']);
    
    return countBalloons == INT_MAX ? 0 : countBalloons;
}