#include <stdio.h>
#include "solve.h"
#include "solve2.h"

int main()
{
    printf("Input 1 for second order equation solve, input 2 for System of Two Equations: ");
    int choose;
    int valid_input = 0;

    while (!valid_input)
    {
        // Try to read an integer
        if (scanf("%i", &choose) == 1 && (choose == 1 || choose == 2))
        {
            // Input is a valid integer
            valid_input = 1;
        }
        else
        {
            // Input is not a valid integer
            printf("Invalid input. Please enter 1 or 2.\n");

            // Clear the input buffer to prevent an infinite loop
            while (getchar() != '\n')
                ;
        }
    }
    if (choose == 1)
    {
        double a, b, c, root1, root2, check_flag;
        printf("Input three coefficients: ");
        int valid_coef = 0;

        while (!valid_coef)
        {
            // Try to read an integer
            if (scanf("%lf %lf %lf", &a, &b, &c) == 3)
            {
                // Input is a valid integer
                valid_coef = 1;
            }
            else
            {
                // Input is not a valid integer
                printf("Invalid coefficients. Try again: \n");

                // Clear the input buffer to prevent an infinite loop
                while (getchar() != '\n')
                    ;
            }
        }
        solve(a, b, c, &check_flag, &root1, &root2);

        FILE *output_file = fopen("output.txt", "a");
        if (output_file == NULL)
        {
            fprintf(stderr, "Error opening the file.\n");
            return 1;
        }
        fprintf(output_file, "Equation: %.2fx^2 + %.2fx + %.2f\n", a, b, c);

        if (check_flag == 2.0)
        {

            printf("Root 1 = %.2f\n", root1);
            printf("Root 2 = %.2f\n", root2);
            fprintf(output_file, "Root 1 = %.2f\n", root1);
            fprintf(output_file, "Root 2 = %.2f\n", root2);
        }
        else if (check_flag == 1.0)
        {

            printf("Root = %.2f\n", root1);
            fprintf(output_file, "Root 1 = %.2f\n", root1);
        }
        else if (check_flag == 0.0)
        {
            printf("No real root.");
            fprintf(output_file, "No real root\n");
        }
        else
        {
            printf("Inf real root.");
            fprintf(output_file, "Inf real root\n");
        }
        fclose(output_file);
    }
    else if (choose == 2)
    {
        double a1, b1, c1, a2, b2, c2, root1sys, root2sys, check_flag;
        printf("Input three coefficients for the first equation ax + by = c: ");
        int valid_coef = 0;

        while (!valid_coef)
        {
            // Try to read an integer
            if (scanf("%lf %lf %lf", &a1, &b1, &c1) == 3)
            {
                // Input is a valid integer
                valid_coef = 1;
            }
            else
            {
                // Input is not a valid integer
                printf("Invalid coefficients. Try again: \n");

                // Clear the input buffer to prevent an infinite loop
                while (getchar() != '\n')
                    ;
            }
        }
        printf("Input three coefficients for the second equation ax + by = c: ");
        valid_coef = 0;

        while (!valid_coef)
        {
            // Try to read an integer
            if (scanf("%lf %lf %lf", &a2, &b2, &c2) == 3)
            {
                // Input is a valid integer
                valid_coef = 1;
            }
            else
            {
                // Input is not a valid integer
                printf("Invalid coefficients. Try again: \n");

                // Clear the input buffer to prevent an infinite loop
                while (getchar() != '\n')
                    ;
            }
        }
        solve2(a1, b1, c1, a2, b2, c2, &check_flag, &root1sys, &root2sys);

        FILE *output_file = fopen("output2.txt", "a");
        if (output_file == NULL)
        {
            fprintf(stderr, "Error opening the file.\n");
            return 1;
        }
        fprintf(output_file, "Equation 1: %.2fx + %.2fy = %.2f\n", a1, b1, c1);
        fprintf(output_file, "Equation 2: %.2fx + %.2fy = %.2f\n", a2, b2, c2);

        if (check_flag == 1.0)
        {

            printf("Root: x=%.2f y=%.2f\n", root1sys, root2sys);
            fprintf(output_file, "Root: x=%.2f y=%.2f\n", root1sys, root2sys);
        }
        else if (check_flag == 0.0)
        {
            printf("No real root.");
            fprintf(output_file, "No real root\n");
        }
        else
        {
            printf("Inf real root.");
            fprintf(output_file, "Inf real root\n");
        }
    }
    else
    {
        printf("Please input number 1 or 2 only.");
    }
}