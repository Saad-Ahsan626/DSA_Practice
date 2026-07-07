#include<iostream>
#include<vector>

using namespace std;

long long sumAndMultiply (int n)
{
    long long sum = 0;
    long long product = 1;
    vector<int> digits;

    while (n > 0) 
    {
        int digit = n % 10;
        if (digit != 0) 
        {
            digits.push_back(digit);
            sum += digit;
            product *= digit;
        }
        n /= 10;
    }

    long long concatenatedNumber = 0;
    for (int i = digits.size() - 1; i >= 0; --i) 
    {
        concatenatedNumber = concatenatedNumber * 10 + digits[i];
    }

    return concatenatedNumber * sum;
}