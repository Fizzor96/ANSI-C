#include <stdio.h>
#include "quadratic.h"

//CMakeLists
//CMakeLists
// /home/marwel/ansi-c/multipara/ora1/multiparadigm-programming-languages/procedural-programming/quadratic
// /mnt/c/Users/szoke/Downloads/ansiC

int main()
{
    printf("Hello, World!\n");
    double x1, x2;
    int resp = solve(1, 4, 4, &x1, &x2);
    printf("Response: %d, (%lf,%lf)\n", resp, x1, x2);
    printf("----------\n");
    struct QuadraticSolution *solution = solve_struct(1, 4, 4);
    printf("Response: %d, (%lf,%lf)\n", solution->status, solution->x1, solution->x2);

    return 0;
}
