
#include <math.h>
#include <stdio.h>
#define M_PI   3.14159265358979323846264338327950288

int main(void)
{
    
    double arrow_diameter;
    printf("Arrow Diameter [mm]: "); 
    scanf("%lf", &arrow_diameter);
    
    double arrow_velocity;
    printf("Arrow Velocity: "); 
    scanf("%lf", &arrow_velocity);
    
    double arrow_mass;
    printf("Arrow Mass [grams]: "); 
    scanf("%lf", &arrow_mass);
    
    // Convert to Kg
    arrow_mass = arrow_mass / 1000;
    // Convert to m
    arrow_diameter = arrow_diameter / 1000;
    // General value for air density
    double air_density = 1.225;
    // Accepted drag coefficient of an arrow
    double drag_coefficient = 1.56;
    // Calculate cross-sectional area of the arrow
    double area = M_PI * pow((arrow_diameter / 2), 2);
    
    // Calculate acceleration due to air resistance
    double air_resistance = (air_density * (pow(arrow_velocity, 2)) * drag_coefficient * area) / (2 * arrow_mass);
    printf("Air Resistance= %lf\n ", air_resistance);
    return air_resistance;
}