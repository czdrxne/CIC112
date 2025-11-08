#include <stdio.h>
#include <stdlib.h>

int main() {
    int fnum, snum, answer;
    char operation;
    
    system("cls");
    printf("=== ARITHMETIC CALCULATOR ===\n");
    
    printf("\nFirst number: ");
    scanf("%d", &fnum);
    
    printf("\nSecond number: ");
    scanf("%d", &snum);
    
    printf("\nOperator (+,-,*,/): ");
    scanf(" %c", &operation);
    
    printf("\n");
    
    if (operation == '+') {
        answer = fnum + snum;
        printf("Answer: %d\n", answer);
    } 
    else if (operation == '-') {
        answer = fnum - snum;
        printf("Answer: %d\n", answer);
    } 
    else if (operation == '*') {
        answer = fnum * snum;
        printf("Answer: %d\n", answer);
    }
    else if (operation == '/') {
        if (snum == 0)
            printf("Error: DIVISION BY ZERO (0)\n");
        else {
            answer = fnum / snum;
            printf("Answer: %d\n", answer);
        }
    } 
    else printf("Error: INVALID OPERATION\n");
    
    return 0;
}
