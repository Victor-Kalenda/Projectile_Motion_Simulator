#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    double windspeed_WE = get_double("Windspeed WE: ");
    double arrow_velocity = get_double("Arrow Velocity: ");
    
    //Calculate initial velocity of the arrow in the y direction
    double initial_velocity = sqrt(pow(arrow_velocity, 2) - pow(windspeed_WE, 2));
    printf("Initial Velocity = %f\n", initial_velocity);
}