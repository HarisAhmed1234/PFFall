#include <stdio.h>

int main() {
    int Intensity_of_light;
    printf("Enter light intensity : ");
    scanf("%d", &Intensity_of_light);
    if (Intensity_of_light > 500) 
    {
        printf("Bright! Max brightness\n");
    } else if (Intensity_of_light >= 100 && Intensity_of_light <= 500) 
    {
        printf("Moderate! Medium brightness\n");
    } else if (Intensity_of_light >= 0 && Intensity_of_light < 100) 
    {
        printf("Low! Minimum brightness\n");
    } else 
    {
        printf("ERROR! Number should be between 0 and 1000.\n");
    }

    return 0;
}
