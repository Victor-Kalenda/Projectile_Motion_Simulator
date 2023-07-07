#include <cs50.h>
#include <math.h>
#include <stdio.h>
#define M_PI   3.14159265358979323846264338327950288

int main(void)
{
    double alpha = get_double("Alpha: ");
    double arrow_velocity = get_double("Arrow Velocity: ");
    
    //Convert to radians
    alpha = alpha/180 * M_PI;
    //Calculate initial velocity of the arrow in the y direction
    double initial_velocity = arrow_velocity * cos(alpha);
    printf("Initial Velocity = %f\n", initial_velocity);
}