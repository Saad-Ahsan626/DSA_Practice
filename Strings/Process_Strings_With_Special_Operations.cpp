#include<iostream>
#include<algorithm>
using namespace std;


string processStr(const string& s)
{
    string result;
    for (char c : s) 
    {
        if (c == '*') 
        {
            if (!result.empty()) 
            {
                result.pop_back();
            }
        } 
        else if (c == '#') 
        {
            result += result; 
        } 
        else if (c == '%') 
        {
            reverse(result.begin(), result.end()); 
        } 
        else 
        {
            result += c; 
        }
    }
    return result;
}