#include <stdio.h>

void solve2(double a1, double b1, double c1, double a2, double b2, double c2, double *check_flag, double *root1, double *root2)
{
    // check_flag = 1: 1 root | check_flag = 0: no real roots | check_flag = -1: infinity roots

    double det = a1 * b2 - a2 * b1;
    if (det != 0)
    {
        *root1 = (c1 * b2 - c2 * b1) / det;
        *root2 = (a1 * c2 - a2 * c1) / det;
        *check_flag = 1.0;
    }
    else
    {
        // Có thể có vô số nghiệm hoặc vô nghiệm
        if (b2 * c1 - b1 * c2 == 0 && a1 * c2 - a2 * c1 == 0)
        {
            *check_flag = -1.0;
            *root1 = 0;
            *root2 = 0;
        }
        else
        {
            *check_flag = 0.0;
            *root1 = 0;
            *root2 = 0;
        }
    }
}