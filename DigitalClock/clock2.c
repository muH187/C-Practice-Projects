#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>

void clearScreen();
int showFormat();
void showTime(int format);
void showDate();

int main() {

    int format = showFormat();
    
    while(1) {
        clearScreen();
        showTime(format);
        showDate();

        sleep(1);
    }

    return 0;
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int showFormat() {
    printf("Choose time format:\n");
    printf("1. 24 Hour Format.\n");
    printf("2. 12 Hour Format.\n");

    int format;
    printf("Make a choice(1/2): ");
    scanf("%d", &format);

    return format;
}

void showTime(int format) {
    time_t rawTime;
    struct tm *currentTime;

    time(&rawTime);
    currentTime = localtime(&rawTime);
    char buffer[50];

    if(format == 1) {
        strftime(buffer, 50, "%H:%M:%S", currentTime);
    } else {
        strftime(buffer, 50, "%I:%M:%S %p", currentTime);
    }
    
    printf("Current Time: %s\n", buffer);
}

void showDate() {
    time_t rawTime;
    struct tm *currentTime;
    char buffer[100];

    time(&rawTime);
    currentTime = localtime(&rawTime);

    strftime(buffer, 100, "%A %B %d %Y", currentTime);

    printf("Date: %s\n", buffer);
}