#include <stdio.h>
#include <stdlib.h>

char options[][30] = {"Rock", "Paper", "Scissors"};
int computerChoice();

int main()
{

    printf("Welcome To Rock Paper Scissors Game\n");

    int userChoice;

    while (userChoice != 0)
    {
        printf("Choose:\n 1. Rock\n 2. Paper\n 3. Scissors\n 0. Exit\n ---: ");
        scanf(" %d", &userChoice);

        computerChoice();

        if(userChoice < 1 || userChoice > 3){
            printf("Please enter between 1-3.\n");
        }

        if (userChoice == 1 && computerChoice() == 1)
        {
            printf("You Lose\n");
            printf("Computer chose Paper\n");
        }
        else if (userChoice == 2 && computerChoice() == 2)
        {
            printf("You Lose\n");
            printf("Computer chose Scissors\n");
        }
        else if (userChoice == 3 && computerChoice() == 0)
        {
            printf("You Lose\n");
            printf("Computer chose Rock\n");
        }
        else if (userChoice == computerChoice())
        {
            printf("It's a Tie!\n");
        }
        else
        {
            printf("You Win!\n");
        }
    }

    printf("You exited the program!\n");

    return 0;
}

int computerChoice()
{
    int randNumber = rand() % 3;
    return randNumber;
}