#include <stdio.h>
#include <ctype.h>

int main() {
    float balance, amount;
    char choice;

    printf("=== SIMPLE BANK SYSTEM ===\n\n");
    printf("Enter your current balance: ");
    scanf(" %f", &balance);

    printf("\nChoose your transaction type:\n");
    printf("  [D] Deposit\n");
    printf("  [W] Withdraw\n");
    printf("  [C] Check Balance\n");
    printf("\nEnter your choice: ");
    scanf(" %c", &choice);
    
    choice = toupper(choice);

    switch (choice) {
        case 'D':
            printf("\nEnter deposit amount: ");
            scanf(" %f", &amount);

            if (amount < 100) {
                printf("\nError: Minimum deposit amount is 100.00.\n");
            } else {
                balance += amount;
                printf("\nDeposit successful!\n");
                printf("\nUpdated balance: %.2f\n", balance);
            }
            break;

        case 'W':
            printf("\nEnter withdrawal amount: ");
            scanf(" %f", &amount);

            if (amount < 100) {
                printf("\nError: Minimum withdrawal amount is 100.00.\n");
            } else if (amount > balance) {
                printf("\nError: Insufficient funds.\n");
            } else {
                balance -= amount;
                printf("\nWithdrawal successful!\n");
                printf("\nUpdated balance: %.2f\n", balance);
            }
            break;

        case 'C':
            printf("\nYour current balance: %.2f\n", balance);
            break;

        default:
            printf("\nInvalid transaction type. Please select D, W, or C.\n");
            break;
    }

    printf("\nThank you for using our service!\n");
    return 0;
}

