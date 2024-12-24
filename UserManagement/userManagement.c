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
void inputCredentials(char* username, char* password);

int main() {

    while(1) {
        printf("\nWelcome to User Management. \n1. Register \n2. Login \n3. Exit\n");

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
                    printf("\nSuccessfully Login! Welcome, %s!\n", users[userIndex].username);
                } else {
                    printf("\nLogin failed! Incorrect username or password!\n");
                }
                break;
            case 3:
                printf("Exiting the Program.\n");
                return 0;
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
        printf("Maximum %d users are supported. No more registerations are allowed!!!\n", USER_MAX);
        return;
    }

    int newIndex = userCount;

    printf("\nRegister a new user.\n");
    inputCredentials(users[newIndex].username, users[newIndex].password);

    userCount++;

    printf("\nRegisteration successful.\n");
}

int loginUser() {
    char username[CREDENTIAL_LENGTH], password[CREDENTIAL_LENGTH];
    inputCredentials(username, password);

    for(int i = 0; i < userCount; i++) {
        if(strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            return i;
        }
    }
    return -1;
}

void fixFgets(char* string) {
    int index = strcspn(string, "\n");
    string[index] = '\0';
}   

void inputCredentials(char* username, char* password) {
    printf("\nEnter your username: ");  
    fgets(username, CREDENTIAL_LENGTH, stdin);
    fixFgets(username);

    printf("Enter password: ");
    fgets(password, CREDENTIAL_LENGTH, stdin);
    fixFgets(password);
}