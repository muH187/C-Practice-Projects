#include<stdio.h>

int num1, num2, choice;
double result;

void printMenu(int *choice);

int main() {
        
    while(choice != 7) {
        printMenu(&choice);

        if(choice < 1 || choice > 7){
            printf("Invalid Choice! Please Choose Correctly...\n");
            continue;
        }

        printf("Please enter the first number: ");
        scanf("%d", &num1);

        printf("Now, enter the second number: ");
        scanf("%d", &num2);

        if(choice == 1) {
            result = num1 + num2;
            printf("\nResult of operation is: %.2lf\n", result);
        } else if(choice == 2) {
            result = num1 - num2;
            printf("\nResult of operation is: %.2lf\n", result);
        } else if(choice == 3) {
            result = num1 * num2;
            printf("\nResult of operation is: %.2lf\n", result);
        } else if(choice == 4) {
            if(num2 == 0) {
                printf("Invalid Argument For Division\n");
                continue;
            }
            result = num1 / num2;
            printf("\nResult of operation is: %.2lf\n", result);
        } else if(choice == 5) {
            result = num1 % num2;
            printf("\nResult of operation is: %.2lf\n", result);
        } else if(choice == 6) {
            result = (num1 * num1) + (num2 * num2);
            printf("\nResult of operation is: %.2lf\n", result);
        }
    }
    
    return 0;
}

void printMenu(int *choice){
    printf("----------------------\n");
    printf("Welcome to Simple Calculator\n");
    printf("\n");
    printf("Choose one of the following options:\n");
    printf(" 1. Add\n 2. Subtract\n 3. Multiply\n 4. Divide\n 5. Modulus\n 6. Power\n 7. Exit\n");

    printf("Now, enter your choice: ");
    scanf("%d", choice);
}