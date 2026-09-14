/* Task 2: Solve a quadratic equation ax^2 + bx + c = 0 and display its roots */
#include <stdio.h>
#include <math.h>
 
int main() {
    double a, b, c, discriminant, real, imag, root1, root2;
 
    printf("Enter coefficients a, b and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
 
    if (a == 0) {
        printf("Not a quadratic equation (a cannot be 0).\n");
        return 0;
    }
 
    discriminant = b * b - 4 * a * c;
 
    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots are real and distinct.\n");
        printf("Root1 = %.2lf\n", root1);
        printf("Root2 = %.2lf\n", root2);
    } else if (discriminant == 0) {
        root1 = -b / (2 * a);
        printf("Roots are real and equal.\n");
        printf("Root1 = Root2 = %.2lf\n", root1);
    } else {
        real = -b / (2 * a);
        imag = sqrt(-discriminant) / (2 * a);
        printf("Roots are complex and imaginary.\n");
        printf("Root1 = %.2lf + %.2lfi\n", real, imag);
        printf("Root2 = %.2lf - %.2lfi\n", real, imag);
    }
 
    return 0;
}
