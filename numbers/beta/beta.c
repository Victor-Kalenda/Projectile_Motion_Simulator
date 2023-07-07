#include <cs50.h>
#include <math.h>
#include <stdio.h>
#define M_PI   3.14159265358979323846264338327950288


double compute_time(double horizontal_velocity, double windspeed_NS, double air_resistance, double distance);
int main(void)
{
    // Insert air_resistance.c
    double arrow_diameter = get_double("Arrow Diameter [mm]:");
    double arrow_velocity = get_double("Arrow Velocity: ");
    double arrow_mass = get_double("Arrow Mass [grams]: ");
    
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
    printf("Air Resistance= %f\n", air_resistance);
    
    
    
    
    
    // For simplicity
    double windspeed_NS = get_double("Windspeed NS: ");
    double distance = get_double("Distance: ");
    double initial_velocity = arrow_velocity;
    double beta = 0;
    bool validity = false;
    do
    {
        // Iterate over beta every 0.001 degrees
        beta = beta + M_PI / 180000;
        // If beta is larger than 45 degrees
        if (beta > M_PI / 4)
        {
            printf("Bow is not strong enough to reach the target\n");
            return 1;
        }
        double horizontal_velocity = initial_velocity * cos(beta);
        
        // Calculate time
        double t = compute_time(horizontal_velocity, windspeed_NS, air_resistance, distance);
        
        // Verify beta
        // Vertical velocity
        double vv = pow(((9.81 * t) / 2), 2);
        // Horizontal velocity
        double hv = pow(horizontal_velocity, 2);
        // Initial velocity
        double iv = pow(initial_velocity, 2);
        
        printf("Beta = %f (vv + hv) = %f (iv) = %f\n", (beta / M_PI * 180), (vv + hv), iv);

        if ((vv + hv) > (iv - 0.01) && (vv + hv) < (iv + 0.01))
        {
            printf("Beta = %f\n(vv + hv) = %f\n(iv) = %f\n", beta, (vv + hv), iv);
            validity = true;
            return beta;
        }
    }
    while (validity == false);
}

double compute_time(double horizontal_velocity, double windspeed_NS, double air_resistance, double distance)
{
    // Insert time.c
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
            printf("T2 = %f ", t2);
            return t2;
        }
    }
    
    // Make sure the value of time is positive or real
    printf("Some value you input does not make sense\n");
    return 1;
}