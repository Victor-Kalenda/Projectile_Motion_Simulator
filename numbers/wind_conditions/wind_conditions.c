#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char wind_conditions[8];
    printf("Wind Conditions m/s[N/S'angle'W/E]: "); 
    scanf("%s", wind_conditions);

    if (strlen(wind_conditions) > 8)
    {
        printf("Usage: m/s[N/S'angle'W/E]\n");
        return 1;
    }
    int v = 0;
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
                printf("Usage: m/s[N/S'angle'W/E]1\n");
                return 1;
            }
            break;
        }
        else
        {
            v++;
            if (v > 3)
            {
                printf("Usage: m/s[N/S'angle'W/E]2\n");
                return 1;
            }
        }
    }
    char NS = wind_conditions[v];
    v++;
    while(1)
    {
        if(isdigit(wind_conditions[v]))
        {
            break;
        }
        else
        {
            printf("Usage: m/s[N/S'angle'W/E]3\n");
            return 1;
        }
    }
    double angle = atoi(&wind_conditions[v]);
    v++;
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
                printf("Usage: m/s[N/S'angle'W/E]4\n");
                return 1;
            }
            break;
        }
        else
        {
            v++;
            if (v > 8)
            {
                printf("Usage: m/s[N/S'angle'W/E]5\n");
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
    // Check for correct usage
    if (angle > 90)
    {
        printf("Angle must be between 0 and 90 degrees\n");
        return 1;
    }
    
    printf("Velocity = %f\n", velocity);
    printf("NS = %c\n", NS);
    printf("Angle = %f\n", angle);
    printf("WE = %c\n", WE);
}