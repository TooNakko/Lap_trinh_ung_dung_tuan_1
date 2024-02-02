#include <stdio.h>
#include <math.h>

void solve(double a, double b, double c, double *check_flag, double *root1, double *root2)
{
    double discriminant;

    // check_flag = 2: 2 different roots | check_flag = 1: 1 root | check_flag = 0: no real roots | check_flag = -1: infinity roots
    discriminant = b * b - 4 * a * c;
    if (a == 0 && b == 0 && c == 0)
    {
        *check_flag = -1.0;
        *root1 = 0.0;
        *root2 = 0.0;
    }
    else
    {
        if (a == 0 && b == 0)
        {
            *check_flag = 0.0;
            *root1 = 0.0;
            *root2 = 0.0;
        }
        else
        {
            if (a == 0)
            {
                *check_flag = 1.0;
                *root1 = -c / b;
                *root2 = -c / b;
            }
            else
            {
                if (discriminant > 0)
                {
                    *check_flag = 2.0;
                    *root1 = (-b + sqrt(discriminant)) / (2 * a);
                    *root2 = (-b - sqrt(discriminant)) / (2 * a);
                }
                else if (discriminant == 0)
                {
                    *check_flag = 1.0;
                    *root1 = -b / (2 * a);
                    *root2 = 0.0;
                }
                else
                {
                    *check_flag = 0.0;
                    *root1 = 0.0;
                    *root2 = 0.0;
                }
            }
        }
    }
}