#include<iostream>
#include<unordered_map>

using namespace std;

int romanToInt(string s) 
{

    unordered_map<char, int> romanMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int total = 0;
    for (size_t i = 0; i < s.length(); ++i) 
    {
        int currentVal = romanMap[s[i]];
        int nextVal = (i + 1 < s.length()) ? romanMap[s[i + 1]] : 0;

        if (currentVal < nextVal) {
            total -= currentVal; 
        } else {
            total += currentVal; 
        }
    }

    return total;
}