#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static const char *CHOICE_NAMES[3] = {"Stone", "Paper", "Scissors"};

int random_number() {
    return rand() % 3;
}

// 0 = tie, 1 = player wins, 2 = computer wins
int compare_choices(int player, int computer) {
    return (player - computer + 3) % 3;
}

const char* choice_to_string(int choice) {
    return CHOICE_NAMES[choice];
}

int main() {
    srand((unsigned int)time(NULL));

    int player, computer, result;

    printf("Welcome to the stone, paper, scissors game!\n");
    printf("Enter 0 for Stone, 1 for Paper, or 2 for Scissors.\n");

    for (int i = 0; i < 3; i++) {
        printf("Round %d: Enter your choice: ", i + 1);

        if (scanf("%d", &player) != 1) {
            while (getchar() != '\n'); // flush bad input so we don't loop forever
            printf("Invalid choice. Please enter 0 for Stone, 1 for Paper, or 2 for Scissors.\n");
            i--;
            continue;
        }

        if (player < 0 || player > 2) {
            printf("Invalid choice. Please enter 0 for Stone, 1 for Paper, or 2 for Scissors.\n");
            i--;
            continue;
        }

        computer = random_number();
        result = compare_choices(player, computer);

        printf("You chose %s, the computer chose %s.\n", choice_to_string(player), choice_to_string(computer));
        if (result == 0) {
            printf("It's a tie!\n");
        } else if (result == 1) {
            printf("You win!\n");
        } else {
            printf("You lose!\n");
        }
    }

    printf("Thank you for playing!\n");
    return 0;
}
