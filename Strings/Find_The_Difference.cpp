#include<iostream>

using namespace std;

char findTheDifference(string s, string t) 
{
    int sum = 0;
    for (char c : s) sum -= c;
    for (char c : t) sum += c;
    return (char)sum;
}