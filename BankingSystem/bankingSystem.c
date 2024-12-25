#include<stdio.h>
#include<string.h>

typedef struct {
    char name[50];
    int accountNo;
    float balance;
} Account;

const char* ACCOUNT_FILE = "account.dat"; 

void createAccount();
void depositMoney();
void withdrawMoney();
void checkBalance();
void fixFgets(char* string);

int main() {

    while(1) {
        printf("\n*** Bank Management System ***\n");
        printf("1. Create Account \n2. Deposit Money \n3. Withdraw Money \n4. Check Balaance \n5. Exit\n");

        int choice;
        printf("Enter your choice(1-5): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                printf("Closing the Bank...\n");
                return 0;
                break;
            default:
                printf("Invalid input! Please choose correctly...\n");
                break;
        }
    }
    

    return 0;
}

void createAccount() {
    Account account;

    FILE* file;
    file = fopen(ACCOUNT_FILE, "ab+");
    if(file == NULL) {
        printf("Unable to open the file!!!\n");
        return;
    }

    char c;
    do{
        c = getchar();
    } while(c != '\n' && c != EOF);

    printf("Enter your name: ");
    fgets(account.name, 50, stdin);
    fixFgets(account.name);

    printf("Enter your account number: ");
    scanf("%d", &account.accountNo);

    account.balance = 0;

    fwrite(&account, sizeof(account), 1, file);
    fclose(file);

    printf("\nAccount created successfully...\n");
}
void depositMoney() {
    printf("Depositing money\n");
}
void withdrawMoney() {
    printf("withdrawing money\n");
}
void checkBalance() {
    FILE *file = fopen(ACCOUNT_FILE, "rb");
    if(file == NULL) {
        printf("Unable to find the file!!!\n");
        return;
    }
 
    // local / temporary variable for account number:
    int acc_no;
    Account acc_read;
    printf("Enter your account number: ");
    scanf("%d", &acc_no);

    while(fread(&acc_read, sizeof(acc_read), 1, file)){
        if(acc_read.accountNo == acc_no) {
            printf("Your account balance is Rs.%.2f\n", acc_read.balance);    
            fclose(file);
            return;
        }
    }
    fclose(file);
    printf("Account NO:%d was not found in our directory...\n", acc_no);
    
}

void fixFgets(char* string) {
    int index = strcspn(string, "\n");
    string[index] = '\0';
}