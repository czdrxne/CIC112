#include <stdio.h>
#include <stdlib.h>

int main() {
    float average,
          sum = 0,
          grades[5];
          
    int length = sizeof(grades) / sizeof(grades[0]);

    system("cls");
    printf("=== GRADE AVERAGE CALCULATOR ===\n");

    for (int i = 0; i < length; i++) {
        printf("\nEnter grade #%d: ", i + 1);
        scanf("%f", &grades[i]);
        sum += grades[i];
    }

    average = sum / length;

    printf("\nTotal: %.2f\n", sum);
    printf("\nAverage: %.2f\n", average);

    if (average >= 75)
        printf("\nYou Passed!\n");
    else
        printf("\nYou Failed.\n");

    return 0;
}
