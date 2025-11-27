/*
    SIMPLE POINT OF SALE CONSOLE APPLICATION (SPOSCA)

    Programmer: Louise Czedrian Laping
    Course: CIC112 Computer Programming 1 (LAB)
    Program: BSCS 1 (BLOCK/SECT 35 | 1251984)
    
    Code Reference: github.com/czdrxne/C1C112/SPOSCA.c
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

const int MAX_ITEMS = 5;
const int MIN_ITEMS = 1;

int isOnlySpaces(const char str[]) {
    for (int i = 0; str[i] != '\0'; i++)
        if (!isspace(str[i])) return 0;
    return 1;
}

void trimSpaces(char str[]) {
    int start = 0;
    while (isspace(str[start])) start++;

    int end = strlen(str) - 1;
    while (end >= start && isspace(str[end])) end--;

    int j = 0;
    for (int i = start; i <= end; i++) {
        str[j++] = str[i];
    }
    str[j] = '\0';
}

int isValidNumberFormat(const char str[]) {
    int numberOfDotSymbol = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            if (numberOfDotSymbol) return 0;
            numberOfDotSymbol = 1;
        }
        else if (!isdigit(str[i])) return 0;
    }
    return 1;
}

int convertToFloat(const char str[], float result[]) {
    return sscanf(str, "%f", result) == 1;
}

int validateNumberInput(const char msg[], float result[]) {
    char input[100];

    while (1) {
        printf("%s", msg);

        if (!fgets(input, sizeof(input), stdin)) continue;
        input[strcspn(input, "\n")] = 0;

        if (isOnlySpaces(input)) {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        trimSpaces(input);

        if (strlen(input) > 11) {
            printf("Number too large. Please enter a smaller number.\n");
            continue;
        }

        if (!isValidNumberFormat(input)) {
            printf("Invalid number format.\n");
            continue;
        }

        float temp;
        if (!convertToFloat(input, &temp)) {
            printf("Invalid number format.\n");
            continue;
        }

        *result = temp;
        return 1;
    }
}

int getItemCount() {
    float temp;
    int count;

    do {
        validateNumberInput("Number of items (1–5): ", &temp);
        count = (int)temp;

        if (count < MIN_ITEMS || count > MAX_ITEMS)
            printf("Input must be between %d and %d.\n", MIN_ITEMS, MAX_ITEMS);

    } while (count < MIN_ITEMS || count > MAX_ITEMS);

    return count;
}

void getItemData(int count, float quantity[], float price[]) {
    char prompt[60];

    for (int i = 0; i < count; i++) {
        sprintf(prompt, "Item #%d quantity: : ", i + 1);
        validateNumberInput(prompt, &quantity[i]);

        sprintf(prompt, "Item #%d price: ", i + 1);
        validateNumberInput(prompt, &price[i]);
    }
}

float computeTotals(int count, float quantity[], float price[], float subtotal[]) {
    float total = 0;

    for (int i = 0; i < count; i++) {
        subtotal[i] = quantity[i] * price[i];
        total += subtotal[i];
    }

    return total;
}

void printReceipt(int count, float quantity[], float price[], float subtotal[], float total) {
    printf("\n==============================================\n");
    printf("                PURCHASE RECEIPT              \n");
    printf("==============================================\n");
    printf("  Item     Qty       Price        Subtotal\n");
    printf("----------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("  #%d     %5.2f     %7.2f     %10.2f\n",
               i + 1, quantity[i], price[i], subtotal[i]);
    }

    printf("----------------------------------------------\n");
    printf("  TOTAL AMOUNT TO PAY: %18.2f\n", total);
    printf("==============================================\n");
    printf("              THANK YOU FOR SHOPPING!         \n");
    printf("==============================================\n\n");
}

int main() {
    int itemCount;
    float quantity[MAX_ITEMS], price[MAX_ITEMS], subtotal[MAX_ITEMS];

    itemCount = getItemCount();
    getItemData(itemCount, quantity, price);

    float total = computeTotals(itemCount, quantity, price, subtotal);

    printReceipt(itemCount, quantity, price, subtotal, total);

    return 0;
}