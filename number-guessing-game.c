#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int user_input,
        attempts = 0,
        max_attempts = 3,
        secret_number = 69;
        
    system("cls");
    printf("=== NUMBER GUESSING GAME ==\n");

    do {
        printf("\nGuess the random number: ");
        scanf(" %d", &user_input);

        attempts++;

        if (user_input == secret_number) {
            printf("\nCorrect guess, You won!");
            break;
        }

        if (attempts >= max_attempts) {
            printf("\nYou failed, Nice try!");
            break;
        }

    } while (user_input != secret_number);
    
    printf("\n");
    return 0;
}

