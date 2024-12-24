#include<stdio.h>
#include<string.h>

#define MAX_USERS 10
#define CREDENTIALS_LENGTH 30

typedef struct {
    char username[CREDENTIALS_LENGTH];
    char password[CREDENTIALS_LENGTH];
} User;

User users[CREDENTIALS_LENGTH];

int userCount = 0;
int userIndex;

void registerUser();
int loginUser();
void inputCredentials(char* username, char* password);
void fixFgets(char* string);

int main() {

    while(1) {
        printf("\nWelcome to User Management.\n");
        printf("1. Register \n2. Login \n3. Exit\n");

        int choice;
        printf("Make a choice(1-3): ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                registerUser();
                break;
            case 2:
                userIndex = loginUser();
                if(userIndex >= 0) {
                    printf("You are logged in successfully. Welcome %s\n", users[userIndex].username);
                } else {
                    printf("Login failed! username or password is correct.\n");
                }
                break;
            case 3:
                printf("Exiting the program...");
                return 0;
                break;
            default:
                printf("Please enter valid input!");
                break;
        }
    }
    

    return 0;
}

void registerUser() {
    if(userCount == MAX_USERS) {
        printf("Max %d users are supported. No more registerations are allowed!!!\n");
    }

    int userCurrIndex = userCount;
    inputCredentials(users[userCurrIndex].username, users[userCurrIndex].password);
    userCount++;

    printf("Registered Successfully!\n");
}

int loginUser() {
    char username[CREDENTIALS_LENGTH];
    char password[CREDENTIALS_LENGTH];

    inputCredentials(username, password);

    for(int i = 0; i < userCount; i++) {
        if(strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            return i;
        }
    }
    return -1;
}

void inputCredentials(char* username, char* password) {
    printf("Enter your username: ");
    fgets(username, CREDENTIALS_LENGTH, stdin);
    fixFgets(username);

    printf("Enter your password: ");
    fgets(password, CREDENTIALS_LENGTH, stdin);
    fixFgets(password);
}

void fixFgets(char* string) {
    int index = strcspn(string, "\n");
    string[index] = '\0';
}