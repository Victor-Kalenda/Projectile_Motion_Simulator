#include <cs50.h>
#include <math.h>
#include <stdio.h>
#define M_PI   3.14159265358979323846264338327950288

int main(void)
{
    double windspeed_WE = get_double("Windspeed WE: ");
    double arrow_velocity = get_double("Arrow Velocity: ");
    
    double alpha = asin(windspeed_WE / arrow_velocity);
    //Convert to degrees 
    alpha = alpha/M_PI * 180;
    printf("Alpha = %f\n", alpha);
}