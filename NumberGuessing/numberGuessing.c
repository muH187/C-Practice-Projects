#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int guess;
int answer;
int attempt;

int main(){
    srand(time(NULL));
    answer = (rand() % 100) + 1;

    printf("Welcome to the world of Guessing Numbers\n");

    do{
        printf("Please enter your guess between (1 to 100): ");
        scanf("%d", &guess);

        if(guess < 1 || guess > 100){
            printf("Invalid range!\n");
            continue;
        }

        if(guess < answer) {
            printf("It's Too Low!\n");
            attempt++;
        } else if(guess > answer){
            printf("It's Too High!\n");
            attempt++;
        } else {
            printf("Correct!\n");
            attempt++;
        }

    }while(answer != guess);

printf("The answer is %d\n", answer);
printf("You got it in %d attempts!", attempt);

    return 0;
}