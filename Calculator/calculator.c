#include<stdio.h>

int num1; num2;
double result;

void printMenu(int choice);
void operation(int choice);

int main() {

    do{
        printMenu(choice);
    }while(choice == 7);
    

    

    return 0;
}

void printMenu(int choice){
    
    int choice;

    printf("----------------------\n");
    printf("Welcome to Simple Calculator\n");
    printf("\n");
    printf("Choose one of the following options:\n");
    printf("1. Add\n 2. Subtract\n 3. Multiply\n 4. Divide\n 5. Modulus\n 6. Power\n 7. Exit\n");

    printf("Now, enter your choice: ");
    scanf("%d", &choice);
}

void operation(int choice){
    printf("Please enter the first number: ");
    scanf("%d", num1);

    printf("Now, enter the second number: ");
    scanf("%d", num2);

    if(choice == 1) {
        return num1 + num2;
    }
}