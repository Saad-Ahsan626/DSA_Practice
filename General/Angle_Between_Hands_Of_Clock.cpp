#include<iostream>
#include<cmath>

using namespace std;

double angleClock(int hour, int minutes) 
{
    
    if (hour >= 12) 
    {
        hour -= 12;
    }

    
    double minuteAngle = minutes * 6; 
    double hourAngle = (hour * 30) + (minutes * 0.5); 

    
    double angle = abs(hourAngle - minuteAngle);
    return min(angle, 360 - angle);
}

