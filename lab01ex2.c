/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main(void)
{
    const double PI = 3.1416;
    double radius, area, volume;
    
    printf("Please enter the radius: ");
    scanf("%lf", & radius);
    
    area   = 4.0 * PI * radius * radius;
    volume = area * radius / 3.0;
    
    printf("Area: %.4lf\n"  , area);
    printf("Volume: %.4lf\n", volume);

    return 0;
}
