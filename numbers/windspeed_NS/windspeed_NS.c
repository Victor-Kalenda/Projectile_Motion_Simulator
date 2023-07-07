#include <cs50.h>
#include <math.h>
#include <stdio.h>
#define M_PI   3.14159265358979323846264338327950288

int main(void)
{
    double velocity = get_double("Velocity: ");
    char NS = get_char("NS: ");
    double angle = get_double("Angle: ");
    
    //Convert to radians
    angle = angle/180 * M_PI;
    printf("Angle= %f\n", angle);
    //Calculate windspeed in the North/South direction
    double windspeed_NS = velocity * cos(angle);
    if (NS == 78)
    {
        printf("Windspeed_NS = %f\n",windspeed_NS);
    }
    else
    {
        windspeed_NS = -1 * windspeed_NS;
        printf("Windspeed_NS = %f\n",windspeed_NS);
    }
}