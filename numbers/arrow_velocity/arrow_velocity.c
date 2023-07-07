#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    double poundage = get_double("Poundage: ");
    double draw_length = get_double("Draw Length: ");
    double arrow_mass = get_double("Arrow Mass: ");
    
    // Calculate the initial velocity of the arrow after it leaves the bow
    double arrow_velocity = sqrt(2 * ((poundage/2.205) * 9.81) * (draw_length / 100) / (arrow_mass / 1000));
    printf("Arrow Velocity= %f\n", arrow_velocity);
    return arrow_velocity;
}