#include<iostream>

using namespace std;

int hammingDistance(int x, int y) {
    int xorResult = x ^ y; 
    int distance = 0;

    
    while (xorResult) {
        distance += xorResult & 1; 
        xorResult >>= 1; 
    }

    return distance;
}