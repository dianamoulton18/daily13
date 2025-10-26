/***********************************************
Author: <insert your name>
Date: <today’s date>
Purpose: <Insert a short description of what
your program does here.>
Time Spent: I worked on this over the span of several days.
***********************************************/
#include <stdio.h>
void    clearBuff(void);
int     userInput(char input);
int     continueInput(char input);
enum    Choices {
    ROCK,
    PAPER,
    SCISSORS
};
enum    continueChoices {
    YES,
    NO
};
int main() {
    char choiceOne, choiceTwo, keepPlaying;
    int  playerOne, playerTwo;
    for (;;) {
        printf("Player 1, it is your turn!\n");
        for (;;) {
            printf("Please choose (r)ock, (p)aper, or (s)cissors: ");
            scanf("%c",&choiceOne);
            clearBuff();
            playerOne = userInput(choiceOne);
            if (playerOne < 3) {
                break;
            } else {
                printf("Sorry, I don't understand. Please re-enter your answer.\n");
            }
        }
        printf("Player 2, it is your turn!\n");
        for (;;) {
            printf("Please choose (r)ock, (p)aper, or (s)cissors: ");
            scanf("%c",&choiceTwo);
            clearBuff();
            playerTwo = userInput(choiceTwo);
            if (playerTwo < 3) {
                break;
            } else {
                printf("Sorry, I don't understand. Please re-enter your answer.\n");
            }
        }
        if (playerOne == ROCK && playerTwo == SCISSORS) {
            printf("Rock breaks scissors. Player one wins!\n");
        } else if (playerOne == PAPER && playerTwo == ROCK) {
            printf("Paper covers rock. Player one wins!\n");
        } else if (playerOne == SCISSORS && playerTwo == PAPER) {
            printf("Scissors cut paper. Player one wins!\n");
        } else if (playerOne == ROCK && playerTwo == PAPER) {
            printf("Paper covers rock. Player two wins!\n");
        } else if (playerOne == PAPER && playerTwo == SCISSORS) {
            printf("Scissors cut paper. Player two wins!\n");
        } else if (playerOne == SCISSORS && playerTwo == ROCK) {
            printf("Rock breaks scissors. Player two wins!\n");
        } else if (playerOne == playerTwo) {
            printf("Draw, nobody wins.\n");
        }
        for (;;) {
            printf("Keep playing? (Y/N): ");
            scanf("%c",&keepPlaying);
            clearBuff();
            keepPlaying = continueInput(keepPlaying);
            if (keepPlaying < 2) {
                break;
            } else {
                printf("Sorry, I don't understand. Please re-enter your answer.\n");
            }
        }
        if (keepPlaying == YES) {
        } else if (keepPlaying == NO) {
            break;
        }
    }
    return 0;
}

int userInput(char input){
    switch (input) {
        case 'r':
        case 'R':
            return ROCK;
        case 'p':
        case 'P':
            return PAPER;
        case 's':
        case 'S':
            return SCISSORS;
        default:
            return 3;
    }
}
int continueInput(char input){
    switch (input) {
        case 'y':
        case 'Y':
            return YES;
        case 'n':
        case 'N':
            return NO;
        default:
            return 2;
    }
}
void clearBuff(void) {
   char c;
   do {
        scanf("%c", &c);
    } while (c != '\n');
}
