#include <cs50.h>
#include <math.h>
#include <stdio.h>
#define M_PI   3.14159265358979323846264338327950288

int main(void)
{
    double initial_velocity = get_double("Initial Velocity: ");
    double windspeed_NS = get_double("Windspeed NS: ");
    double distance = get_double("Distance: ");
    double air_resistance = get_double("Air Resistance: ");

    double
    double x = pow((initial_velocity + windspeed_NS), 2) - (4 * (air_resistance / 2) * distance);
    printf("X = %f\n", x);

    if(x < 0)
    {
        printf("Bow is not strong enough to reach the target\n");
        return 1;
    }
    double y = sqrt(x);
    printf("y = %f\n", y);
    double t1 = (initial_velocity + windspeed_NS + sqrt(x)) / air_resistance;
    x = -1 * x;
    double t2 = (initial_velocity + windspeed_NS + x) / air_resistance;
    if (t1 > t2)
    {
        if (t2 < 0)
        {
            printf("T1 = %f\n", t1);
        }
        printf("T2 = %f\n", t2);
    }
    else
    {
        printf("T1 = %f\n", t1);
    }
}