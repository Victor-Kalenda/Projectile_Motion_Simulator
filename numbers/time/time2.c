#include <cs50.h>
#include <math.h>
#include <stdio.h>
#define M_PI   3.14159265358979323846264338327950288

int main(void)
{
    double horizontal_velocity = get_double("Initial Velocity: ");
    double windspeed_NS = get_double("Windspeed NS: ");
    double distance = get_double("Distance: ");
    double air_resistance = get_double("Air Resistance: ");

    // For simplicity, define variables for the quadratic formula
    double v = horizontal_velocity + windspeed_NS;
    double d = distance;
    double a = air_resistance / 2;
    
    // Check if the bow is strong enough to hit the target
    double check = pow(v, 2) - (4 * d * a);
    if (check < 0)
    {
        printf("Arrow cannot reach target\n");
        return 1;
    }
    
    // Calculate the times it will take the arrow to reach the target
    double x = sqrt(pow(v, 2) - (4 * d * a));
    double t1 = (v + x) / (2 * a);
    x = x * -1;
    double t2 = (v + x) / (2 * a);

    // Determine which time makes the most sence
    if (t1 < t2)
    {
        if (t1 > 0)
        {
            printf("T1 = %f\n", t1);
            return t1;
        }
    }
    else
    {
        if (t2 > 0)
        {
            printf("T2 = %f\n", t2);
            return t2;
        }
    }
    
    // Make sure the value of time is positive or real
    printf("Some value you input does not make sense\n");
    return 1;
}