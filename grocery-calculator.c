#include <stdio.h>
#include <stdlib.h>

int main() {
    int item_count;
    float price, total_bill = 0.0;

    system("cls");
    printf("=== GROCERY CALCULATOR ===\n");

    printf("\nEnter number of items: ");
    scanf("%d", &item_count);

    for (int i = 0; i < item_count; i++) {
        printf("\nEnter price for item #%d: ", i + 1);
        scanf("%f", &price);
        total_bill += price;
    }

    printf("\nYour total bill: %.2f\n", total_bill);
    return 0;
}

