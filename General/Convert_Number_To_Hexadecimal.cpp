#include<iostream>
using namespace std;

string toHex(int num) 
{
    if (num == 0) return "0";
    string hex = "0123456789abcdef";
    string result;
    while (num && result.size() < 8) 
    {
        result = hex[num & 0xf] + result;
        num >>= 4;
    }
    return result;
}