#include <stdio.h>
#include <math.h>
int main() {
    float a, b, c;
    float discriminant, root1, root2;
	printf("Enter the coeffients of a b c (a, b, c): ");
    scanf("%f %f %f", &a, &b, &c);
	discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        root1 = (-b + sqrtf(discriminant)) / (2 * a);
        root2 = (-b - sqrtf(discriminant)) / (2 * a);
        printf("The roots are real and distinct:\n");
        printf("Root 1 = %.2f\n", root1);
        printf("Root 2 = %.2f\n", root2);
    } else if (discriminant == 0) {
    	root1 = -b / (2 * a);
        printf("The root is real and repeated:\n");
        printf("Root 1 = %.2f\n", root1);
    } else {
        float realPart = -b / (2 * a);
        float imaginaryPart = sqrtf(-discriminant) / (2 * a);
        printf("The roots are complex:\n");
        printf("Root 1 = %.2f + %.2fi\n", realPart, imaginaryPart);
        printf("Root 2 = %.2f - %.2fi\n", realPart, imaginaryPart);
    }

    return 0;
}
