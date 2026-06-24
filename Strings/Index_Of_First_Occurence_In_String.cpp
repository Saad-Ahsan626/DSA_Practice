#include<iostream>
#include<string>

using namespace std;

int strStr(string haystack, string needle) 
{
    if (needle.empty()) return 0;

    size_t found = haystack.find(needle);
    if (found != string::npos) {
        return found;
    }
    return -1;
}