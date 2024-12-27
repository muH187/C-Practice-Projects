#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>

int displayMenu();
void fillTime(char* buffer, int format);
void fillDate(char* buffer);
void clearScreen();

int main() {

    char time[50];
    char date[100];

    int format = displayMenu();

    if(format != 1 && format != 2) {
        printf("Invalid input.!\n");
        return -1;
    }
    
    while(1) {
        fillTime(time, format);
        fillDate(date);
        clearScreen();

        printf("Current Time: %s\n", time);
        printf("Date: %s", date);

        sleep(1);
    }
    return 0;
}

int displayMenu() {
    int format;
    printf("Choose the time format.\n");
    printf("1. 24 hour fomat \n2. 12 hour format\n");
    printf("Make the choice(1-2): ");
    scanf("%d", &format);

    return format;
}

void fillTime(char* buffer, int format) {
    time_t rawTime;
    struct tm *currentTime;

    time(&rawTime);
    currentTime = localtime(&rawTime);

    if(format == 1) {
        strftime(buffer, 50, "%H:%M:%S", currentTime);
    } else if(format == 2) {
        strftime(buffer, 50, "%I:%M:%S %p", currentTime);
    }
}

void fillDate(char* buffer) {
    time_t rawTime;
    struct tm *currentTime;

    time(&rawTime);
    currentTime = localtime(&rawTime);

    strftime(buffer, 100, "%A %B %d %Y", currentTime);
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}