#include<stdio.h>


#define USER_MAX 10

typedef struct {
    char username[30];
    char password[30];
} User;

User users[USER_MAX];

int choice;
int userIndex;
int userCount = 0;

void registerUser();
int loginUser();

int main() {

    while(1) {
        printf("Welcome to User Management. \n1. Register \n2. Login \n3. Exit\n");

        printf("Select an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                registerUser();
                break;
            case 2:
                userIndex = loginUser();
                if(userIndex >= 0) {
                    printf("Welcome successful! Welcome, %s!\n\n", users[userIndex].username);
                } else {
                    printf("Login failed! Incorrect username or password!\n\n");
                }
                break;
            case 3:
                printf("Exiting Program.\n");
                break;
            default:
                printf("Invalid input please try again!\n\n");
                break;  
        }
    }

    return 0;
}

void registerUser() {
    printf("Dummy registeration for now.\n");
}

int loginUser() {
    return -1;
}