#include <cs50.h>
#include <math.h>
#include <stdio.h>
#define M_PI   3.14159265358979323846264338327950288

string aim_RL;

int main(void)
{
    double velocity = get_double("Velocity: ");
    char WE = get_char("WE: ");
    double angle = get_double("Angle: ");
    
    //Convert to radians
    angle = angle/180 * M_PI;
    //Calculate windspeed in West/East direction
    double windspeed_WE = velocity * sin(angle);
    if (WE == 69)
    {
        aim_RL = "Left";
        printf("Windspeed_WE = %f, %s\n",windspeed_WE, aim_RL);
    }
    else
    {
        aim_RL = "Right";
        printf("Windspeed_WE = %f, %s\n",windspeed_WE, aim_RL);
    }
}