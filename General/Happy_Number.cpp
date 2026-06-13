#include<iostream>
using namespace std;

int getNext(int n)
{
    int totalSum = 0;
    while (n > 0) 
    {
        int d = n % 10;
        n /= 10;
        totalSum += d * d;
    }
    return totalSum;
}

bool isHappy(int n)
{
    int slow = n, fast = n;
    do {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    } while (slow != fast);
    return slow == 1;
}

