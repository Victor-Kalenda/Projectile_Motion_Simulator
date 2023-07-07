#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // Calculate the initial velocity of the arrow after it leaves the bow
    double poundage = get_double("Poundage: ");
    double draw_length = get_double("Draw Length: ");
    double arrow_mass = get_double("Arrow Mass: ");

    // For simplicity
    arrow_mass = arrow_mass / 1000;
    draw_length = draw_length / 100;

    double spring_force = (poundage / 2.205) * 9.81;
    double spring_constant = spring_force / draw_length;
    double mechanical_energy = (spring_constant * (pow(draw_length, 2))) / 2;
    double arrow_velocity = sqrt((2 * mechanical_energy) / arrow_mass);
    printf("Arrow Velocity = %f\n", arrow_velocity);
}