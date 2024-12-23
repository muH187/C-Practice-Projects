#include<stdio.h>
#include<string.h>

#define USER_MAX 10
#define CREDENTIAL_LENGTH 30

typedef struct {
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];
} User;

User users[USER_MAX];

int choice;
int userIndex;
int userCount = 0;

void registerUser();
int loginUser();
void fixFgets(char*);
void inputPassword(char*);

int main() {

    while(1) {
        printf("Welcome to User Management. \n1. Register \n2. Login \n3. Exit\n");

        printf("Select an option: ");
        scanf("%d", &choice);
        getchar();

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

    if(userCount == USER_MAX) {
        printf("Maximum %d are supported. No more registerations are allowed!!!\n", USER_MAX);
        return;
    }

    int newIndex = userCount;

    printf("\nRegister a new user.\n");
    printf("Enter your username: ");
    fgets(users[newIndex].username, CREDENTIAL_LENGTH, stdin);
    fixFgets(users[newIndex].username);
    inputPassword(users[newIndex].password);

    userCount++;

    printf("Registeration successful.");

}

int loginUser() {
    char username[CREDENTIAL_LENGTH], password[CREDENTIAL_LENGTH];

    printf("Enter your username: ");
    fgets(username, CREDENTIAL_LENGTH, stdin);
    fixFgets(username);
    inputPassword(password);

    for(int i = 0; i < userCount; i++) {
        if(strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password)) {
            return i;
        }
    }
    return -1;
}

void fixFgets(char* string) {
    int index = strcspn(string, "\n");
    string[index] = '\0';
}   

void inputPassword(char* password) {
    printf("Enter password: ");
    fgets(password, CREDENTIAL_LENGTH, stdin);
    fixFgets(password);
}