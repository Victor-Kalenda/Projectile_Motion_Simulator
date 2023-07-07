#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#define M_PI   3.14159265358979323846264338327950288

// Function Prototypes
double compute_WE(double arrow_velocity, double angle, char WE);
double compute_NS(double arrow_velocity, char NS, double angle);
double compute_arrow_velocity(double poundage, double arrow_mass, double draw_length);
double compute_alpha(double windspeed_WE, double arrow_velocity);
double compute_initial_velocity(double windspeed_WE, double arrow_velocity);
double compute_air_resistance(double arrow_diameter, double arrow_velocity, double arrow_mass);
double compute_time(double horizontal_velocity, double windspeed_NS, double distance, double air_resistance);

// Global Variables
char *aim_RL;
// Alpha variable
double A;

int main(void)
{
    // Make a space to make it more user friendly
    printf("\n\n\n");
    // Get the wind conditions for the experiment and check the values
    char wind_conditions[8];
    printf("Wind Conditions m/s[N/S'angle'W/E]: ");
    scanf("%s", wind_conditions);
    // Insert wind_conditions.c
    if (strlen(wind_conditions) > 8)
    {
        printf("Usage: m/s[N/S'angle'W/E]\n");
        return 1;
    }
    int v = 0;
    
    // Find the velocity of the wind
    while(1)
    {
        if (isdigit(wind_conditions[v]))
        {
            break;
        }
        else
        {
            printf("Usage: m/s[N/S'angle'W/E]\n");
            return 1;
        }
    }
    double velocity = atoi(wind_conditions);
    v++;
    
    // Find the direction north or south
    while(1)
    {
        if (isalpha(wind_conditions[v]))
        {
            if (wind_conditions[v] == 78 || wind_conditions[v] == 83)
            {
                break;
            }
            else
            {
                printf("Usage: m/s[N/S'angle'W/E]\n");
                return 1;
            }
            break;
        }
        else
        {
            v++;
            if (v > 3)
            {
                printf("Usage: m/s[N/S'angle'W/E]\n");
                return 1;
            }
        }
    }
    char NS = wind_conditions[v];
    v++;
    
    // Find the angle east or west
    while(1)
    {
        if(isdigit(wind_conditions[v]))
        {
            break;
        }
        else
        {
            printf("Usage: m/s[N/S'angle'W/E]\n");
            return 1;
        }
    }
    double angle = atoi(&wind_conditions[v]);
    v++;
    
    // Find the direction east or west
    while(1)
    {
        if (isalpha(wind_conditions[v]))
        {
            if (wind_conditions[v] == 69 || wind_conditions[v] == 87)
            {
                break;
            }
            else
            {
                printf("Usage: m/s[N/S'angle'W/E]\n");
                return 1;
            }
            break;
        }
        else
        {
            v++;
            if (v > 8)
            {
                printf("Usage: m/s[N/S'angle'W/E]\n");
                return 1;
            }
        }
    }
    char WE = wind_conditions[v];

    // Check for exceptionally high wind speeds
    if (velocity > 22.352)
    {
        printf("Why are you shooting in these winds?\n");
        return 1;
    }

    // Check for correct usage of directional input
    if (angle > 90)
    {
        printf("Angle must be between 0 and 90 degrees\n");
        return 1;
    }
    
    
    
    
    
    // Get and check user input which is needed for the calculations
    double arrow_mass;
    printf("Arrow Mass [grams]: "); 
    int check_arrow_mass = scanf("%lf", &arrow_mass);
    if (check_arrow_mass == 0)
    {
        printf("Input is invalid\n");
        scanf("%*s");
        return 1;
    }
    if (arrow_mass > 100 || arrow_mass <= 0)
    {
        printf("Arrow Mass is unrealistic\n");
        return 1;
    }

    double arrow_diameter;
    printf("Arrow Diameter [mm]: ");
    int check_arrow_diameter = scanf("%lf", &arrow_diameter);
    if (check_arrow_diameter == 0)
    {
        printf("Input is invalid\n");
        scanf("%*s");
        return 1;
    }
    if (arrow_diameter > 20 || arrow_diameter <= 0)
    {
        printf("Arrow Diameter is unrealistic\n");
        return 1;
    }
    
    double poundage;
    printf("Poundage [lbs]: ");
    int check_poundage = scanf("%lf", &poundage);
    if (check_poundage == 0)
    {
        printf("Input is invalid\n");
        scanf("%*s");
        return 1;
    }
    if (poundage <= 0 || poundage > 200)
    {
        printf("Poundage is unrealistic\n");
        return 1;
    }
    
    double distance;
    printf("Shooting Distance [m]: ");
    int check_distance = scanf("%lf", &distance);
    if (check_distance == 0)
    {
        printf("Input is invalid\n");
        scanf("%*s");
        return 1;
    }
    if (distance <= 0)
    {
        printf("Distance is unrealistic\n");
    }
    
    double draw_length;
    printf("Draw Length (string at rest to string at full draw) [cm]: ");
    int check_draw_length = scanf("%lf", &draw_length);
    if (check_draw_length == 0)
    {
        printf("Input is invalid\n");
        scanf("%*s");
        return 1;
    }
    if (draw_length > 200 || draw_length <= 0)
    {
        printf("Draw Length is unrealistic\n");
        return 1;
    }





    double windspeed_WE = compute_WE(velocity, angle, WE);
    double windspeed_NS = compute_NS(velocity, NS, angle);
    double arrow_velocity = compute_arrow_velocity(poundage, arrow_mass, draw_length);
    if (angle != 0)
    {
        if (velocity != 0)
        {
            A = compute_alpha(windspeed_WE, arrow_velocity);
            // Print how many degrees to the right or left you must aim
            printf("\nAim %lf degrees %s", A, aim_RL);
        }
        else
        {
            A =
            printf("\nAim dead ahead");
        }
    }
    else
    {
        A = 0;
        printf("\nAim dead ahead");
    }
    double initial_velocity = compute_initial_velocity(windspeed_WE, arrow_velocity);
    double air_resistance = compute_air_resistance(arrow_diameter, arrow_velocity, arrow_mass);





    // Focus on the other dimension to find a valid vertical velocity
    // Insert beta.c
    double beta = 0;
    int validity = 0;
    do
    {
        // Iterate over beta every 0.001 degrees
        beta = beta + M_PI / 180000;
        // If beta is larger than 45 degrees
        if (beta > M_PI / 4)
        {
            printf(" but unfortunately bow is not strong enough to reach the target\n");
            return 1;
        }
        double horizontal_velocity = initial_velocity * cos(beta);
        double t = compute_time(horizontal_velocity, windspeed_NS, distance, air_resistance);
        if (t == -1)
        {
            return 1;
        }
        // Verify beta
        // Vertical velocity
        double vv = pow(((9.81 * t) / 2), 2);
        // Horizontal velocity
        double hv = pow(horizontal_velocity, 2);
        // Initial velocity
        double iv = pow(initial_velocity, 2);
        
        if ((vv + hv) > (iv - 0.1) && (vv + hv) < (iv + 0.1))
        {
            printf(" and %lf degrees Up\n", (beta / M_PI * 180));
            validity = 1;
            return beta;
        }
    }
    while (validity == 0);
    return 0;
}





double compute_arrow_velocity(double poundage, double arrow_mass, double draw_length)
{
    // For simplicity
    arrow_mass = arrow_mass / 1000;
    draw_length = draw_length / 100;

    double spring_force = (poundage / 2.205) * 9.81;
    double spring_constant = spring_force / draw_length;
    double mechanical_energy = (spring_constant * (pow(draw_length, 2))) / 2;
    double kinetic_energy = 0.739 * mechanical_energy + 0.286;
    double arrow_velocity = sqrt((2 * kinetic_energy) / arrow_mass);
    return arrow_velocity;
}





double compute_WE(double velocity, double angle, char WE)
{
    // Insert windspeed_WE.c
    // Convert to radians
    angle = angle/180 * M_PI;
    // Calculate windspeed in West/East direction
    double windspeed_WE = velocity * sin(angle);
    if (WE == 69)
    {
        aim_RL = "Left";
        return windspeed_WE;
    }
    else
    {
        aim_RL = "Right";
        return windspeed_WE;
    }
}





double compute_NS(double velocity, char NS, double angle)
{
    // Insert windspeed_NS.c
    // Convert to radians
    angle = angle/180 * M_PI;
    // Calculate windspeed in the North/South direction
    double windspeed_NS = velocity * cos(angle);
    if (NS == 78)
    {
        return windspeed_NS;
    }
    else
    {
        windspeed_NS = -1 * windspeed_NS;
        return windspeed_NS;
    }
}





double compute_alpha(double windspeed_WE, double arrow_velocity)
{
    // Insert alpha.c
    double alpha = asin(windspeed_WE / arrow_velocity);
    // Convert to degrees
    alpha = alpha/M_PI * 180;
    return alpha;
}





double compute_initial_velocity(double windspeed_WE, double arrow_velocity)
{
    // Insert initial_velocity.c
    // Calculate initial velocity of the arrow in the y direction
    double initial_velocity = sqrt(pow(arrow_velocity, 2) - pow(windspeed_WE, 2));
    return initial_velocity;
}





double compute_time(double horizontal_velocity, double windspeed_NS, double distance, double air_resistance)
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
        printf(" but unfortunately arrow cannot reach target\n");
        return -1;
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
            return t1;
        }
    }
    else
    {
        if (t2 > 0)
        {
            return t2;
        }
    }

    // Make sure the value of time is positive and real
    printf("Some value you input does not make sense\n");
    return -1;
}





double compute_air_resistance(double arrow_diameter, double arrow_velocity, double arrow_mass)
{
    // Insert air_resistance.c
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
    return air_resistance;
}