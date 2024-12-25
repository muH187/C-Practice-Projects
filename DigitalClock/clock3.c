#include<stdio.h>
#include<time.h>

void fillTime();

int main() {

    int format;
    printf("Choose the time format.\n");
    printf("1. 24 hour fomat \n2. 12 hour format\n");
    printf("Make the choice(1-3): ");
    scanf("%d", &format);

    return 0;
}

void fillTime() {
    time_t rawTime;
    struct currentTime;

    time(rawTime);
    currentTime = localtime(rawTime);
}