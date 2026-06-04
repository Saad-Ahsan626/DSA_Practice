#include<iostream>
#include<string>
using namespace std;

bool backspaceCompare(string s, string t) 
{
    int i = s.length() - 1;
    int j = t.length() - 1;
    
    while (i >= 0 || j >= 0) 
    {
        int backCountS = 0;
        while (i >= 0 && (s[i] == '#' || backCountS > 0)) 
        {
            if (s[i] == '#') 
            {
                backCountS++;
            } 
            else 
            {
                backCountS--;
            }
            i--;
        }
        
        int backCountT = 0;
        while (j >= 0 && (t[j] == '#' || backCountT > 0)) 
        {
            if (t[j] == '#') 
            {
                backCountT++;
            } 
            else 
            {
                backCountT--;
            }
            j--;
        }
        
        char charS = (i >= 0) ? s[i] : '\0';
        char charT = (j >= 0) ? t[j] : '\0';
        
        if (charS != charT) 
        {
            return false;
        }
        
        i--;
        j--;
    }
    
    return true;
}